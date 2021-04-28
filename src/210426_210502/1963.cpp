#include <iostream>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;

int t, ans;
string s1, s2;
bool is_prime[10010];
int visited[10010];

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

int bfs(){
    queue<string> q;
    string cur, next;
    
    q.push(s1);
    visited[stoi(s1)] = 1;
    
    while(!q.empty()){
        
        cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            for(char c='0';c<='9';c++){
                if(c=='0' && i==0) continue;
                
                next = cur;
                next[i] = c;
                int snext = stoi(next);
                
                if(is_prime[snext] && visited[snext] == 0){
                    q.push(next);
                    visited[snext] = visited[stoi(cur)] + 1;
                }
            }
        }
        
        
    }
    
    return visited[stoi(s2)] - 1;
}



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    make_prime();
    
    
    cin >> t;
    
    while(t--){
        cin >> s1 >> s2;
        
        int b = bfs();

        if(b == -1){
            cout << "Impossible\n";
        }
        else{
            cout << b << '\n';
        }
        
        
        for(int i=0;i<=10000;i++){
            visited[i] = 0;
        }
    }
	
	return 0;
}