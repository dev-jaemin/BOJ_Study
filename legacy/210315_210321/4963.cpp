#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int w, h, cnt;

int matrix[55][55];
bool visited[55][55];
vector<int> answer;


vector<pair<int, int>> make_adj(int i, int j){
    vector<pair<int, int>> ret;
    
    if(i > 1 && matrix[i-1][j] == 1){
        ret.push_back({i-1, j});
    }
    
    if(i < h && matrix[i+1][j] == 1){
        ret.push_back({i+1, j});
    }
    
    if(j > 1 && matrix[i][j-1] == 1){
        ret.push_back({i, j-1});
    }
    
    if(j < w && matrix[i][j+1] == 1){
        ret.push_back({i, j+1});
    }
    
    
    if(i > 1 && j > 1 && matrix[i-1][j-1] == 1){
        ret.push_back({i-1, j-1});
    }
    
    if(i < h && j < w && matrix[i+1][j+1] == 1){
        ret.push_back({i+1, j+1});
    }
    
    if(i < h && j > 1 && matrix[i+1][j-1] == 1){
        ret.push_back({i+1, j-1});
    }
    
    if(i > 1 && j < w && matrix[i-1][j+1] == 1){
        ret.push_back({i-1, j+1});
    }
    
    return ret;
}

void bfs(int a, int b){
    queue<pair<int, int>> q;

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
        
        for(int i=0;i<adj.size();i++){
            next_first = adj[i].first;
            next_second = adj[i].second;
            
            if(!visited[next_first][next_second]){
                q.push({next_first, next_second});
                visited[next_first][next_second] = true;
            }
        }
        
        
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> w >> h;
    
    while(w != 0 || h != 0){
        //initialize
        for(int i=1;i<=51;i++){
            for(int j=1;j<=51;j++){
                matrix[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        cnt = 0;
 
        
        //행렬 입력받기
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin >> matrix[i][j];
            }
        }
        
        //BFS 실행
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(!visited[i][j] && matrix[i][j] == 1){
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        
        
        cout << cnt << '\n';
        
        cin >> w >> h;
    }

	return 0;
}