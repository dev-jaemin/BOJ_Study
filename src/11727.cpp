#include <iostream>
#include <algorithm>


using namespace std;

int n;
int dp[100000];


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-2] * 2 + dp[i-1]) % 10007;
    }
    
    cout << dp[n] << '\n';
    
	
	return 0;
}