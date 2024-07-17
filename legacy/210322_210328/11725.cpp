#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, node1, node2;
int tree[100010];
vector<int> adj[100010];
int answer[100010];
bool visited[100010];


void dfs(int start){
    visited[start] = true;
    
    int next = 0;
    
    for(int i=0;i<adj[start].size();i++){
        next = adj[start][i];
        
        if(!visited[next]){
            dfs(next);
            answer[next] = start;
        }
    }    
}

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    tree[0] = 1;
    
    for(int i=0;i<n-1;i++){
        cin >> node1 >> node2;
        
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    for(int i=2;i<=n;i++){
        cout << answer[i] << '\n';
    }
    
	
	return 0;
}