#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, ans;
int matrix[11][11];
bool visited[11];
vector<int> v;

void Calculate(){
    int sum = 0;
    
    for(int i=0;i<n-1;i++){
        sum += matrix[v[i]][v[i+1]];    
    }
    sum += matrix[v[n-1]][v[0]];
    
    if(sum < ans) ans = sum;
}

int dfs(int cur, int cnt){
    
    if(cnt == n){
        Calculate();
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i] && matrix[cur][i] != 0){
            visited[i] = true;
            v.push_back(i);
            dfs(i, cnt + 1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

https://jdselectron.tistory.com/10
//현재위치가 cur, cnt일때 그동안 왔던 길의 총합
int dfs2(int cur, int cnt, int sum, int start){
    if(cnt == n){
        return sum;
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i] && matrix[cur][i] != 0){
            visited[i] = true;
            if(ans < dfs2(i, cnt + 1, sum+matrix[cur][i])){
                return;
            }
            visited[i] = false;
            
        }
    }
    
    return sum;
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
        dfs(i, 0);
    }
    
    cout << ans << '\n';
    
	
	return 0;
}