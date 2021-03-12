#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n, m, k, graph_n;
bool visited[20010];

void makeAdjList(vector<int> adj[], int count, int size){
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


void dfs(vector<int> adj[], int start){
    visited[start] = true;
    
    //cout << start << ' ';
    
    for(int i=0;i<adj[start].size();i++){
        int nextNode = adj[start][i];
        if(!visited[nextNode]){
            dfs(adj, nextNode);
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    
    while(k--){
        cin >> n >> m;
        
        graph_n = 0;
    
        vector<int> adj[20010];
        makeAdjList(adj, m, n);
        for(int i=1;i<=n;i++) visited[i] = false;
    
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(adj, i);
                graph_n++;
            }
        }
        
        if(graph_n == 2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
	
	return 0;
}