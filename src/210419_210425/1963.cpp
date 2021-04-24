#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

int t;
string s1, s2;
bool is_prime[100010];

void make_prime(){
    is_prime[0] = true;
    is_prime[1] = true;
    
    for(int i=2;i*i<=10000;i++){
        if(is_prime[i]) continue;
        
        for(int j=i*i;j<=10000;j+=i){
            is_prime[j] = true;
        }
    }
    
    for(int i=0;i<=10000;i++) is_prime[i] = !is_prime[i];
}

void dfs(int cnt, int* ans){
    if(cnt > *ans) return;
    if(s1 == s2){
        *ans = min(cnt, *ans);
    }
    
    for(int i=0;i<4;i++){
        for(int j='0';j<'9';j++){
            if(i==0 && j=='0' && s1[i] != j){
                continue;
            }
             
            char tmp = s1[i];
            s1[i] = j;
            if(is_prime[stoi(s1)]){
                dfs(cnt+1, ans);
            }
            s1[i] = tmp;
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    make_prime();
    
    cin >> t;
    
    while(t--){
        cin >> s1 >> s2;
        
        int ans = 1e9;
        dfs(0, &ans);
        
        cout << ans << '\n';
    }
	
	return 0;
}