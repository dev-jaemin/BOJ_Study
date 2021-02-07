#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int a, b;
char tmp; //tmp에는 ,를 저장할 예정 / tmp가 int형일 경우 cin 함수가 ,을 제대로 인식하지 못한다. 

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t; // t를 먼저 받아준다.

    for(int i=0;i<t;i++){
        cin >> a >> tmp >> b;
        cout << a+b << '\n';
    }
	
	return 0;
}