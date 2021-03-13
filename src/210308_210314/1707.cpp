#include <iostream>
#include <algorithm>
#include <vector>

#define RED 1
#define BLUE -1


using namespace std;

int n, m, k;
int color_matrix[20010];
bool bipartite;

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


void dfs(vector<int> adj[], int start, int color){
    color_matrix[start] = color;

    for(int i=0;i<adj[start].size();i++){
        int nextNode = adj[start][i];
        
        if(color == color_matrix[nextNode]){
            bipartite = false;
            return;
        }
        
        if(color_matrix[nextNode] == 0){
            dfs(adj, nextNode, -color);
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

        vector<int> adj[20010];
        makeAdjList(adj, m, n);
        
        for(int i=1;i<=n;i++){
            color_matrix[i] = 0;
        }
        
        bipartite = true;
        
        for(int i=1;i<=n;i++){
            if(!bipartite) break;
            if(color_matrix[i] == 0) dfs(adj, i, RED);
        }
        
        
        if(bipartite) cout << "YES\n";
        else cout << "NO\n";
    
    }
	
	return 0;
}