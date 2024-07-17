#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, tmp, a, b, n_zero, n_one;
vector<int> v1, v2;
long long ans;

bool compare(int a, int b){
    return a > b;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        
        if(tmp > 1){
            v1.push_back(tmp);    
        }
        else if(tmp < 0){
            v2.push_back(tmp);
        }
        else{
            if(tmp == 1) n_one++;
            else n_zero++;
        }
        
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), compare);
    
    int n1 = v1.size();
    int n2 = v2.size();
    
    while(n1 > 1){
        a = v1[n1-1];
        b = v1[n1-2];
        
        ans += a*b;
        n1 -= 2;
    }
    
    while(n2 > 1){
        a = v2[n2-1];
        b = v2[n2-2];
        
        ans += a*b;
        n2 -= 2;
    }
    
    if(n1 == 1){
        ans += v1[0];
    }
    
    if(n2 == 1 && n_zero == 0){
        ans += v2[0];
    }
	
    
    cout << ans + n_one;
    
	return 0;
}