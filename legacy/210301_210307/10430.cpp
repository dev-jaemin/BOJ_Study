#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int A,B,C;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> C;
    
    cout << (A+B)%C << '\n';
    cout << ((A%C) + (B%C)) << '\n';
    cout << (A*B)%C << '\n';
    cout << ((A%C) * (B%C)) << '\n';
    
    
	
	return 0;
}