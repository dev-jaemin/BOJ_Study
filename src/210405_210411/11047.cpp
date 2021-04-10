#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>


using namespace std;

int n, k, ans, tmp;
stack<int> s;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        s.push(tmp);
    }
    
    while(k > 0 && !s.empty()){
        int c = k/s.top(); 
        ans += c;
        
        k = k - s.top() * c;
        s.pop();
    }

     cout << ans << '\n';
    
	
	return 0;
}