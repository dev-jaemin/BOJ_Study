#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100010];
int dp[100010]; // dp[k] : k번째 수가 마지막인 부분합들 중 가장 큰 합의 값
int answer;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    dp[1] = arr[1]; // 초항은 당연히 첫번째 숫자 값이다.
    
    for(int i=2;i<=n;i++){
        if(dp[i-1] > 0){ // 이전에 더해놨던 게 양수라서 더하면 이득인 경우
            dp[i] = dp[i-1] + arr[i]; // 전 항에서 계산한 값(dp[i-1])을 더해줌.
        }
        else{ // 이전에 더해놨던게 음수라서 더하면 오히려 손해인 경우
            dp[i] = arr[i]; // 굳이 더하지 않음.
        }
    }
    
    answer = dp[1];
    for(int i=2;i<=n;i++){
        if(answer < dp[i]) answer = dp[i]; // dp[n]이 항상 최댓값은 아니기 때문에, dp의 값들 중 최댓값을 찾아야한다.
    }
    
    cout << answer << '\n';
	
	return 0;
}