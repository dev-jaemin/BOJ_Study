#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;
typedef vector<pair<int, int>> vp;


int n, minn;

int matrix[110][110];
int visited[110][110];
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


void bfs_cont(int a, int b, int cont){
    queue<pair<int, int>> q;

    int cur_i = 0;
    int cur_j = 0;
    int new_i = 0;
    int new_j = 0;
    
    visited[a][b] = 1;
    
    q.push({a, b});
    
    while(!q.empty()){
        cur_i = q.front().first;
        cur_j = q.front().second;
        
        matrix[cur_i][cur_j] = cont;
        q.pop();
        
        for(int i=0;i<4;i++){
            new_i = cur_i + di[i];
            new_j = cur_j + dj[i];
            
            if(matrix[new_i][new_j] != 0 && visited[new_i][new_j] == 0){
                q.push({new_i, new_j});
                visited[new_i][new_j] = 1;
            }
        }
        
        
    }
}


void check_continent(){
    int cont = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i][j] != 0 && visited[i][j] == 0){
                bfs_cont(i, j, cont);
                cont++;
            }
        }
    }
}




void bfs(int a, int b){
    queue<pair<int, int>> q;

    int cur_i = 0;
    int cur_j = 0;
    int new_i = 0;
    int new_j = 0;
    int cont = matrix[a][b];
    
    bool loop_sw = true;
    
    visited[a][b] = 1;
    
    q.push({a, b});
    
    while(!q.empty() && loop_sw){
        cur_i = q.front().first;
        cur_j = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            if(cur_i + di[i] > 0 && cur_i + di[i] <= n) new_i = cur_i + di[i]; //범위확인
            else continue;
            if(cur_j + dj[i] > 0 && cur_j + dj[i] <= n) new_j = cur_j + dj[i];
            else continue;
            
            if(matrix[new_i][new_j] == 0 && visited[new_i][new_j] == 0){// 바다인지 확인하고, visit했는지 확인하고
                q.push({new_i, new_j});
                visited[new_i][new_j] = visited[cur_i][cur_j] + 1;
            }
            else if(matrix[new_i][new_j] != 0){//바다가 아니라면
                if(cont != matrix[new_i][new_j]){// 다른 대륙 발견
                    if(minn > visited[cur_i][cur_j] - 1){ // 최솟값인지 비교
                        minn = visited[cur_i][cur_j] - 1;
                    }
                    loop_sw = false;
                }
            }
        }
        
        
    }
}


void clear_visited(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[i][j] = 0;
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> n;
    minn = 1000000;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> matrix[i][j];
        }
    }
    
    check_side();
    check_continent();
    
    
    for(int i=0;i<side.size();i++){
        clear_visited();
        bfs(side[i].first, side[i].second);
    }
    
    cout << minn << '\n';

	return 0;
}