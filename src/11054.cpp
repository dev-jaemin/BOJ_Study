#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
int dp[1010][2]; // 왼쪽에서부터 LIS, 오른쪽에서부터 LIS값을 각각 저장하기 위해 2차원 배열 사용
int arr[1010];
int answer, sum;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    dp[1][0] = 1;
    dp[n][1] = 1;
    
    int max1 = 1;
    int max2 = 1;
    for(int i=2;i<=n;i++){
        max1 = 1;
        
        for(int j=1;j<i;j++){
            if(arr[j] < arr[i]){
                if(dp[j][0] + 1 > max1){
                    max1 = dp[j][0] + 1;
                }
            }
        }
        
        dp[i][0] = max1;
    }
    
    for(int i=n-1;i>=1;i--){
        max2 = 1;
        
        for(int j=n;j>i;j--){
            if(arr[j] < arr[i]){
                if(dp[j][1] + 1 > max2){
                    max2 = dp[j][1] + 1;
                }
            }
        }
        
        dp[i][1] = max2;
    }
    
    //꼭 마지막 수에서 끝나야 최댓값인건 아니므로, 전수조사해야함.
    for(int i=1;i<=n;i++){
        if(dp[i][0] + dp[i][1] - 1 > answer) answer = dp[i][0] + dp[i][1] - 1;
    }
    
    cout << answer << '\n';
    
	
	return 0;
}