#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

vector<int> test;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    for(int i=0;i<10;i++){
        test.push_back(i);
    }
    //vector는 range가 초과해도 에러가 발생하지 않는다.
    cout << test[10] << '\n';
    
	return 0;
}