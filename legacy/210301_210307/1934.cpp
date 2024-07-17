#include <iostream>
#include <algorithm>

using namespace std;

int t, a, b;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> a >> b;
 
        cout << a * b / gcd(a, b) << '\n';
        
    }
	
	return 0;
}