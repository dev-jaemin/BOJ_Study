#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int answer;
char k; // k : 입력되는 숫자들을 임시로 저장, answer : k를 계속 더한 값을 저장


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while(n--){ // 이렇게 반복문 짜면 정확히 n번 실행된다. 대신, n값이 계속 바뀌므로 변수 n을 다시 사용해야 한다면 이렇게 짜면 안된다.
        cin >> k;
        answer += (k - 48); // 문자 '1'은 변수 k에 49로 저장되어 있기 때문에 차이(48)을 빼주면 숫자 1이 된다.
    }
    
    cout << answer << '\n';
	
	return 0;
}