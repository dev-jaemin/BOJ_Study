#include <iostream>
#include <algorithm>


using namespace std;

int t, n;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){ // t번의 테스트 케이스를 진행하기 위해
        int answer;
        int tmp_answer; // dp를 채워가면서 각 상황에서의 최댓값을 저장하는 변수
        int sticker[100010][3]; //sticker 점수 정보 저장, sticker[n][1] : 위쪽 스티커 점수, sticker[n][2] : 아래쪽 스티커 점수
        int dp[100010][3]; 
        /* dp table
            dp[n][0] : 마지막 줄 스티커를 떼지 않은 상황에서 점수 최대값
            dp[n][1] : 마지막 줄 위 스티커를 뗀 상황에서 점수 최대값
            dp[n][2] : 마지막 줄 아래 스티커를 뗀 상황에서 점수 최대값
        */
        
        cin >> n;
        
        for(int i=1;i<=n;i++){
            cin >> sticker[i][1]; // sticker 점수 정보 받기(점수 입력 순서를 조심해야 한다. 첨에 위에서 아래방향으로 받는걸로 실수한 덕분에 10분 날림ㅠ)
        }
        for(int i=1;i<=n;i++){
            cin >> sticker[i][2]; // sticker 점수 정보 받기
        }
        
        
        dp[1][0] = 0;
        dp[1][1] = sticker[1][1];
        dp[1][2] = sticker[1][2]; // 초항 설정, 열이 하나인데 마지막 줄 아래 스티커를 뗀 상황이라면 그냥 그 열의 아래쪽 스티커만 뗀 상황이다.
        
        
        for(int i=2;i<=n;i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));    //마지막 줄 스티커를 안 뗄 것이라면, 그냥 전 항의 값 중 가장 큰 값을 받으면 된다.
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[i][1];    //마지막 줄 윗 스티커를 뗄 것이라면, 전 줄에서 아무것도 안 뗀 것 vs 전 줄 아래 스티커 뗀 것 중 큰 값을 받는다.
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + sticker[i][2];    //마지막 줄 아래 스티커를 뗄 것이라면, 전 줄에서 아무것도 안 뗀 것 vs 전 줄 윗 스티커 뗀 것 중 큰 값을 받는다.
        }
        
        answer = max(dp[n][0], max(dp[n][1], dp[n][2]));
        
        cout << answer << '\n';
    }
	
	return 0;
}