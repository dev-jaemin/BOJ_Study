#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
int dp[1010];
int arr[1010];
int answer;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    dp[1] = 1;
    
    int maxx = 1;
    for(int i=2;i<=n;i++){
        maxx = 1;
        
        for(int j=1;j<i;j++){
            if(arr[j] < arr[i]){
                if(dp[j] + 1 > maxx){
                    maxx = dp[j] + 1;
                }
            }
        }
        
        dp[i] = maxx;
    }
    
    //꼭 마지막 수에서 끝나야 최댓값인건 아니므로, 전수조사해야함.
    for(int i=1;i<=n;i++){
        if(dp[i] > answer) answer = dp[i];
    }
    
    cout << answer << '\n';
    
	
	return 0;
}