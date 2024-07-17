#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;

long long fiveCount(long long n){
    long long ret = 0;
    long long i = 5;
    
    while(n / i > 0){
        ret += n / i;
        i *= 5;
    }
    
    return ret;
}

long long twoCount(long long n){
    long long ret = 0;
    long long i = 2;
    
    while(n / i > 0){
        ret += n / i;
        i *= 2;
    }
    
    return ret;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    int two_n = twoCount(n) - twoCount(m) - twoCount(n-m);
    int five_n = fiveCount(n) - fiveCount(m) - fiveCount(n-m);
    
    cout << min(two_n, five_n) << '\n';
	
	return 0;
}