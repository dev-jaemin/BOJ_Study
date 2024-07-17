#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int e, s, m;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> e >> s >> m;
    
    long long ans = 1;
    
    if(e == 15) e = 0;
    if(s == 28) s = 0;
    if(m == 19) m = 0;
    
    while(!(ans%15 == e && ans%28 == s && ans%19 == m)){
        ans++;
    }
    
    cout << ans << '\n'; 
	
	return 0;
}