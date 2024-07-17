#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

int n, k;
long long cache[210][210];

long long rec(int a, int b){
    //cout << a << ' ' << b << '\n';
     // 어떤 수를 정수 한 개로 더하는 경우의 수 : 본인 하나만 더하면 되기 때문에 1
    // 1을 k개의 음이 아닌 정수로 더하는 경우의 수 : 1 + 0*(k-1) 이므로 한 가지가 있다.
    if(b == 1 || b == 0) return 1;
    
    long long& ret = cache[a][b];
    
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i=0;i<=a;i++){
        ret += rec(a-i, b-1) % 1000000000;
    }

    
    return ret % 1000000000;
}



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    memset(cache, -1, sizeof(cache));
    
    cout << rec(n, k) << '\n';
    
	
	return 0;
}