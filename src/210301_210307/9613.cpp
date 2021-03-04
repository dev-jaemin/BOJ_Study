#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int t, n;
long long answer;

int gcd(int a, int b){
    if(b==0) return a;
    
    return gcd(b, a%b);
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        answer = 0;
        int inputs[110];
        
        for(int i=1;i<=n;i++) cin >> inputs[i];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n && i != j;j++){
                answer += gcd(inputs[i], inputs[j]);
            }
        }
        
        cout << answer << '\n';
        
    }
	
	return 0;
}