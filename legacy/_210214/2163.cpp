#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int answer;


void cut(int cur_n, int cur_m){
    //cout << "now n : " << cur_n << "now m : " << cur_m << '\n';
    
    if(cur_n == 1 && cur_m == 1) return; // n,m 둘다 1일 경우 재귀함수 정지
    else if(cur_n == 1){ // 현재 n이 1일경우 m쪽만 분할해주면 됌.
        answer++;
        if(cur_m%2 == 1){ //현재 m이 홀수라면
            cut(cur_n, cur_m/2);
            cut(cur_n, cur_m/2 + 1);
        }
        else{ // 현재 m이 짝수라면
            cut(cur_n, cur_m/2);
            cut(cur_n, cur_m/2);
        }
    }
    else if(cur_m == 1){ // 현재 m이 1일경우 n쪽만 분할해주면 됌.
        answer++;
        if(cur_n%2 == 1){ //현재 n이 홀수라면
            cut(cur_n/2, cur_m);
            cut(cur_n/2 + 1, cur_m);
        }
        else{ // 현재 n이 짝수라면
            cut(cur_n/2, cur_m);
            cut(cur_n/2, cur_m);
        }
    }
    else{ //일반적인 경우
        answer++;
        if(cur_n > cur_m){
            if(cur_n%2 == 1){ //현재 n이 홀수라면
                cut(cur_n/2, cur_m);
                cut(cur_n/2 + 1, cur_m);
            }
            else{ // 현재 n이 짝수라면
                cut(cur_n/2, cur_m);
                cut(cur_n/2, cur_m);
            }
        }
        else{
            if(cur_m%2 == 1){ //현재 m이 홀수라면
                cut(cur_n, cur_m/2);
                cut(cur_n, cur_m/2 + 1);
            }
            else{ // 현재 m이 짝수라면
                cut(cur_n, cur_m/2);
                cut(cur_n, cur_m/2);
            }
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    cut(n,m);
    
    cout << answer << '\n';
	
	return 0;
}