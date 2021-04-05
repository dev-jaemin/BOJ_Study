#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>


using namespace std;

int v, n1, n2, d, end_node;
vector<int> adj[100010];
vector<int> dist[100010];
bool visited[100010];
long long answer;


void dfs(int start,long long length){
    if(visited[start]) return;
    
    visited[start] = true;
    int next = 0;
    
    if(answer < length){
        answer = length;
        end_node = start;
    }
    
    for(int i=0;i<adj[start].size();i++){
        next = adj[start][i];
        
        if(!visited[next]){
            dfs(next, length + dist[start][i]);
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> v;
    
    for(int i=1;i<v;i++){
        cin >> n1 >> n2 >> d;
        
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        
        dist[n1].push_back(d);
        dist[n2].push_back(d);
    }
    
    dfs(1, 0);
    
    for(int i=0;i<=v;i++){
        visited[i] = false;
    }
    answer = 0;
    
    dfs(end_node, 0);
    
    cout << answer << '\n';
    
    
	return 0;
}