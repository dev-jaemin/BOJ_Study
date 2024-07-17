#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, ans;
int matrix[11][11];
bool visited[11];
vector<int> v;


//현재위치가 cur, cnt일때 그동안 왔던 길의 총합
void dfs2(int cur, int cnt, int sum, int start){
    if(sum > ans) return;
    
    
    if(visited[cur]){
        if(cur != start) return;
        else{
            if(cnt == n){
                ans = min(ans, sum);
            }
            
            return;
        }
    }
    
    visited[cur] = true;
    
    
    for(int i=1;i<=n;i++){
        if(matrix[cur][i] != 0){
            //visited[i] = true;
            dfs2(i, cnt + 1, sum+matrix[cur][i], start);
            //visited[i] = false;
        }
    }
    
    visited[cur] = false;
    
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
    
    ans = 1e9;
    
    for(int i=1;i<=n;i++){
        dfs2(i, 0, 0, i);
    }
    
    cout << ans << '\n';
    
	
	return 0;
}