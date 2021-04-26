#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

string s;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >>  s;
    
    s[1] = '2';
    
    cout << stoi(s) + 1 << '\n';
    
	return 0;
}