#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
int dp[1010];
int arr[1010];
int tmp, answer;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    
    for(int i=2;i<=n;i++){
        tmp = arr[i];
        for(int j=1;j<i;j++){
            if(arr[j] < arr[i] && tmp < dp[j] + arr[i]){ // 10 10 20은 증가수열이 아닌가 봅니다..ㅋㅋㅋㅋㅋㅋㅋ
                tmp = dp[j] + arr[i];
            }
        }
        
        dp[i] = tmp;
    }
    
    for(int i=1;i<=n;i++){
        if(answer < dp[i]) answer = dp[i];
    }
    
    cout << answer << '\n';

	return 0;
}