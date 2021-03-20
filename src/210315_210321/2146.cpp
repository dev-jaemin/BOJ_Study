#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;
typedef vector<pair<int, int>> vp;


int n, minn;

int matrix[110][110];
bool visited[110][110];
vp side;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void check_side(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i][j] != 0){
                if(matrix[i-1][j] == 0){
                    side.push_back({ i,j });
                }
                else if(matrix[i+1][j] == 0){
                    side.push_back({ i,j });
                }
                else if(matrix[i][j-1] == 0){
                    side.push_back({ i,j });
                }
                else if(matrix[i][j+1] == 0){
                    side.push_back({ i,j });
                }
            }
        }
    }
}

void check_continent(){
    int cont = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i][j] != 0 && !visited[i][j]){
                bfs2(i, j, cont);
            }
            cont++;
        }
    }
    
    
}

void bfs2(int a, int b, int cont){
    queue<pair<int, int>> q;

    int cur_i = 0;
    int cur_j = 0;
    int new_i = 0;
    int new_j = 0;
    
    visited[a][b] = true;
    
    q.push({a, b});
    
    while(!q.empty()){
        cur_i = q.front().first;
        cur_j = q.front().second;
        
        matrix[cur_i][cur_j] = cont;
        q.pop();
        
        for(int i=0;i<4;i++){
            new_i = adj[i].first;
            new_j = adj[i].second;
            
            if(!visited[new_i][new_j]){
                q.push({new_i, new_j});
                visited[new_i][new_j] = true;
            }
        }
        
        
    }
}

//최신화필요
void bfs(int a, int b){
    queue<pair<int, int>> q;

    int cur_i = 0;
    int cur_j = 0;
    int new_i = 0;
    int new_j = 0;
    
    visited[a][b] = true;
    
    q.push({a, b});
    
    while(!q.empty()){
        cur_i = q.front().first;
        cur_j = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            new_i = adj[i].first;
            new_j = adj[i].second;
            
            if(!visited[new_i][new_j]){
                q.push({new_i, new_j});
                visited[new_i][new_j] = true;
            }
        }
        
        
    }
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
    
    check_side();
    check_continent();
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0;i<side.size();i++){
        bfs(side[i].first, side[i].second);
    }

	return 0;
}