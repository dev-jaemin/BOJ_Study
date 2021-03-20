#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int n;
//int matrix[30][30];
char matrix[30][30];
bool visited[30][30];
vector<int> answer;
pair<int, int> start;

vector<pair<int, int>> make_adj(int i, int j){
    vector<pair<int, int>> ret;
    
    if(i > 1 && matrix[i-1][j] == '1'){
        ret.push_back({i-1, j});
    }
    
    if(i < n && matrix[i+1][j] == '1'){
        ret.push_back({i+1, j});
    }
    
    if(j > 1 && matrix[i][j-1] == '1'){
        ret.push_back({i, j-1});
    }
    
    if(j < n && matrix[i][j+1] == '1'){
        ret.push_back({i, j+1});
    }
    
    return ret;
}

void bfs(int a, int b){
    queue<pair<int, int>> q;
    int cnt = 0;
    int first = 0;
    int second = 0;
    int next_first = 0;
    int next_second = 0;
    
    visited[a][b] = true;
    
    q.push({a, b});
    
    while(!q.empty()){
        first = q.front().first;
        second = q.front().second;
        
        
        vector<pair<int, int>> adj = make_adj(first, second);
        
        q.pop();
        cnt++;
        
        
        for(int i=0;i<adj.size();i++){
            next_first = adj[i].first;
            next_second = adj[i].second;
            
            if(!visited[next_first][next_second]){
                q.push({next_first, next_second});
                visited[next_first][next_second] = true;
            }
        }
        
        
    }
    
    answer.push_back(cnt);
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> matrix[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!visited[i][j] && matrix[i][j] == '1'){
                bfs(i, j);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << '\n';
    
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
    
    
    
	return 0;
}