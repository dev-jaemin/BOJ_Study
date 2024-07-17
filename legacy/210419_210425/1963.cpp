#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

int t;
string s1, s2;
bool is_prime[10010];
bool visited[10010];

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


//dfs() : 현재상태에서 최종목적지까지 가는 최소 횟수
void dfs(int cnt, int* ans){
    if(cnt > *ans) return;
    if(visited[stoi(s1)]) return;
    if(s1 == s2){
        //cout << cnt << '\n';
        *ans = min(cnt, *ans);
        return;
    }

    visited[stoi(s1)] = true;
    
    for(int i=0;i<4;i++){
        for(char j='0';j<='9';j++){
            if((i==0 && j=='0') || s1[i] == j){
                continue;
            }
            
        
             
            char tmp = s1[i];
            s1[i] = j;
            //cout << stoi(s1) << '\n';
            if(is_prime[stoi(s1)]){
                //cout << s1 << '\n';
                dfs(cnt+1, ans);
            }
            s1[i] = tmp;
        }
    }
    visited[stoi(s1)] = false;
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