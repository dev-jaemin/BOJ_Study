#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

int n, m, v;
vector<int> adj[1010];
bool visited[1010];

void makeAdjList(int count, int size){
    int a, b;
    
    for(int i=1;i<=count;i++){
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1;i<=size;i++){
        if(!adj[i].empty()) sort(adj[i].begin(), adj[i].end());
    }
}

void dfs(int start){
    visited[start] = true;
    
    cout << start << ' ';
    
    for(int i=0;i<adj[start].size();i++){
        int nextNode = adj[start][i];
        if(!visited[nextNode]){
            dfs(nextNode);
        }
    }
    
    
}

void bfs(int start){
    queue<int> q;
    
    visited[start] = true;
    
    q.push(start);
    
    while(!q.empty()){
        int curNode = q.front();
        q.pop();
        cout << curNode << ' ';
        
        for(int i=0;i<adj[curNode].size();i++){
            int nextNode = adj[curNode][i];
            
            if(!visited[nextNode]){
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }
    
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> v;
    
    makeAdjList(m, n);
    
    dfs(v);
    cout << '\n';
    
    for(int i=1;i<=n;i++){
        visited[i] = false;
    }
    
    bfs(v);
    cout << '\n';

    
	
	return 0;
}