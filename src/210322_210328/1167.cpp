#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int v, tmp, node, d, end_node;
vector<int> adj[100010];
vector<int> dist[100010];
bool visited[100010];
long long answer, dfsi;


long long dfs(int start){
    visited[start] = true;
    
    int next = 0;
    long long d = 0;
    long long maxx = 0;
    
    for(int i=0;i<adj[start].size();i++){
        next = adj[start][i];
        
        if(!visited[next]){
            d = dist[start][i] + dfs(next);
            if(maxx < d){
                maxx = d;
                end_node = next;
            }
        }
    }
    
    return maxx;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> v;
    
    for(int i=1;i<=v;i++){
        cin >> tmp;
        cin >> node;
        while(node != -1){
            cin >> d;
            
            adj[i].push_back(node);
            dist[i].push_back(d);
            
            cin >> node;
        }
    }
    
    /*for(int i=1;i<=v;i++){
        dfsi = dfs(i);
        if(answer < dfsi){
            answer = dfsi;
        }
        
        for(int i=1;i<=v;i++) visited[i] = false;
    }*/
    
    answer = max(dfs(1), dfs(end_node));
    
    cout << answer << '\n';
    
    
	return 0;
}