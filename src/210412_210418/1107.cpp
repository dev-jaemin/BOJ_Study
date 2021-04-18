#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m, tmp, c1, c2, c3;
bool is_broken[10];

bool is_possible(int ch){
    if(ch == 0){
        return !is_broken[0];
    }
    
    while(ch > 0){
        if(is_broken[ch%10]){
            return false;
        }
        
        ch = ch/10;
    }
    
    return true;
}

int jari(int ch){
    int ret = 0;
    
    if(ch == 0) return 1;
    
    while(ch > 0){
        ret++;
        
        ch = ch/10;
    }
    
    return ret;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        cin >> tmp;
        is_broken[tmp] = true;
    }
    
    //채널변경 버튼만 사용
    c1 = n - 100;
    if(c1 < 0) c1 = -c1;
    
    //c2 초기화
    c2 = 1e9;
    c3 = 1e9;
    
    int i = 0;
    for(;i<=n;i++){
        if(is_possible(n-i)){
            c2 = jari(n-i) + i;
            break;
        }
        
    }
    
    int j = 0;
    for(;j<8888888;j++){
        if(is_possible(n+j)){
            c3 = jari(n+j) + j;
            break;
        }
    }
    
    cout << min(c1, min(c2, c3)) << '\n';
    
	
	return 0;
}