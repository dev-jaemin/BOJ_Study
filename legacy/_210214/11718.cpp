#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
string str;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, str); // 한 줄을 받아온다.
    
    while(str != "\0"){ // 받은 문장이 \0 (=NULL)이 아닐경우 아래 내용을 반복한다.
        cout << str << '\n'; // 문장을 출력한다.
        getline(cin, str); // 다시 문장을 입력받는다.
    }
	
	return 0;
}