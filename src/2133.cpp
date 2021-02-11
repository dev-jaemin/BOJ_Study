#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
long long dp[35];


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    
    for(int i=5;i<=n;i++){
        if(i%2 == 1) continue;
        
        dp[i] = dp[i-2] * 3 + dp[i-4] * 11;
    }
    
    cout << dp[n] << '\n';
	
	return 0;
}