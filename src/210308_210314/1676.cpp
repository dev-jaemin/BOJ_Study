#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    cout << n / 5 + n / 25 + n / 125 << '\n';
	
	return 0;
}