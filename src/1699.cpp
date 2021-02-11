#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
long long dp[100010];
long long minn;
vector<long long> v;




int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i*i<=n;i++){
        dp[i*i] = 1;
        v.push_back(i*i);
    }

    for(int i=2;i<=n;i++){
        if(dp[i] == 1) continue;
        
        minn = i;
        for(int j=0;j<v.size();j++){
            if(v[j] >= i) break;
            
            if(minn > dp[v[j]] + dp[i-v[j]]){
                minn = dp[v[j]] + dp[i-v[j]];
            }
        }
        
        dp[i] = minn;
    }
    
    cout << dp[n] << '\n';
    
    
	
	return 0;
}