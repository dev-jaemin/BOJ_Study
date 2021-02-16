#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1010][1010]; //dp[i][k] : i번째 카드팩까지 이용하여 카드를 k개 살 때의 최댓값
int p[1010];
int tmp_max;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    
    

    for(int k=1;k<=n;k++){
        dp[1][k] = p[1] * k;
        dp[k][1] = p[1];
    }
    
    for(int i=2;i<=n;i++){
        for(int k=2;k<=n;k++){
            tmp_max = dp[i-1][k];
            
            for(int m=1;m*i<=k;m++){
                if(tmp_max < dp[i-1][k-i*m] + m*p[i]){ // p[i]를 안 살건지, 한 개 사고 (k-i)개를 p[i-1]이하에서 살건지, .......
                    tmp_max = dp[i-1][k-i*m] + m*p[i];
                }
            }
            
            dp[i][k] = tmp_max;
        }
       
    }
    
    cout << dp[n][n] << '\n';
    
	
	return 0;
}