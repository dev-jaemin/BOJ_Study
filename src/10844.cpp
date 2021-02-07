#include <iostream>
#include <algorithm>


using namespace std;

long long n, answer;  // 숫자가 크기 때문에 long long 같이 큰 숫자를 넣을 수 있는 자료형을 선택한다. 무심결에 int형으로 했다가 처음에 틀렸다.
long long dp[110][10]; // dp[n][l] : n : 자리 수, l : 마지막 숫자



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
    }
    
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1];
        for(int j=1;j<=8;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;  //문제에서 1000000000으로 나눈 나머지를 달라고 했으므로
        }
        dp[i][9] = dp[i-1][8];
    }
    
    for(int i=0;i<=9;i++){
        answer += dp[n][i];
    }
	
    
    cout << answer % 1000000000 << '\n';
    
	return 0;
}