#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n, t, answer;
bool visited[1010];

void makeAdjList(int count, int size, vector<int> adj[]){
    int a, b;
    
    for(int i=1;i<=count;i++){
        cin >> a;
        
        adj[i].push_back(a);
    }
}

void dfs(int cur, int start, vector<int> adj[]){
    if(cur == start && visited[cur]){
        answer++;
        return;
    }
    
    visited[cur] = true;
    //cout << start << ' ';
    
    int nextNode = adj[cur][0];
    dfs(nextNode, start, adj); 
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        vector<int> adj[1010];
        answer = 0;
        
        makeAdjList(n, n, adj);
        
        for(int i=1;i<=n;i++){
            visited[i] = false;
        }
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i, i, adj);
            }
        }
        
        cout << answer << '\n';
    }
    
    


    
	
	return 0;
}