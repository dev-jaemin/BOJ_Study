#include <iostream>
#include <algorithm>


using namespace std;

int n;
long long dp[100][2]; // dp[n][l] n:자릿수, l:마지막 숫자(ex. dp[4][1] = 4자리면서 맨 뒷자리 수가 1인 이친수)
long long answer;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    dp[1][0] = 0; // 한자린데 0으로 끝나는 이친수는 없음. (0으로 시작하면 안되므로)
    dp[1][1] = 1; // 1
    
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1]; // 0으로 끝나는 상황 : 전 항이 0으로 끝나던 1로 끝나던 상관없음.
        dp[i][1] = dp[i-1][0]; // 1로 끝나는 상황 : 전 항이 1로 끝나면 1끼리 붙게 되므로 안됨. 전 항은 무조건 0으로 끝나야 함.
    }
    
    answer = dp[n][0] + dp[n][1];
    
    cout << answer << '\n';
	
	return 0;
}