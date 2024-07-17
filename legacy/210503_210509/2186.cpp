#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int n, m, k, ans;
char matrix[100][100];
int dp[100][100][100];
string input;


void clear_dp(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int l=0;l<100;l++)
            dp[j][i][l] = -1;
        }
    }
}


int rec(int a, int b, int level){
    if(dp[a][b][level] != -1) return dp[a][b][level];
    if(level >= input.size()-1) return 1;
     
    
    int ret = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    
    
    for(int d=0;d<4;d++){
        for(int i=1;i<=k;i++){
            pair<int, int> next = { a + dx[d]*i, b + dy[d]*i };
            if(next.first < 0 || next.first >= m) continue;
            if(next.second < 0 || next.second >= n) continue;
                
                
            if(matrix[next.first][next.second] == input[level + 1]){
                ret += rec(next.first, next.second, level + 1);
                
            }
        }
    }
    
    dp[a][b][level] = ret;
    return ret;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[j][i];
        }
    }
    
    cin >> input;
    
    
    clear_dp();
    
    //finding startig points
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[j][i] == input[0]){
                ans += rec(j, i, 0);
                
            }
        }
    }
    
    cout << ans << '\n';
    
	return 0;
}