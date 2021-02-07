#include <iostream>
#include <algorithm>


using namespace std;

int n;
long long dp[1010][10];
long long sum; //
long long answer;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<=9;i++){ // 초항을 직접 넣는 코드. 한 자리 수는 무조건 오르막 수 이므로 하나씩 채워넣음.
        dp[1][i] = 1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            sum = 0;
            for(int k=0;k<=j;k++){
                sum += dp[i-1][k];
            }
            
            dp[i][j] = sum % 10007;
        }
    }
    
    for(int i=0;i<=9;i++){
        answer += dp[n][i] % 10007;
    }
    
    cout << answer % 10007 << '\n';
	
	return 0;
}