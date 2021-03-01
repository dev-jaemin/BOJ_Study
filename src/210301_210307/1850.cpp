#include <iostream>
#include <algorithm>

using namespace std;

long long a, b;

long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    
    for(long long i=0;i<gcd(a,b);i++){
        cout << 1;
    }
    
    
    
    cout << '\n';
    
    
	return 0;
}