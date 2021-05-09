#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int r, c, ans;
bool a[26];
char matrix[25][25];


void dfs(int x, int y, int level){
    if(level > ans){
        ans = level;
    }
    
    //up
    if(y != 0 && !a[matrix[x][y-1]-'A']){
        a[matrix[x][y-1]-'A'] = true;
        dfs(x, y-1, level+1);
        a[matrix[x][y-1]-'A'] = false;
    }
    
    //down
    if(y != r-1 && !a[matrix[x][y+1]-'A']){
        a[matrix[x][y+1]-'A'] = true;
        dfs(x, y+1, level+1);
        a[matrix[x][y+1]-'A'] = false;
    }
    
    //left
    if(x != 0 && !a[matrix[x-1][y]-'A']){
        a[matrix[x-1][y]-'A'] = true;
        dfs(x-1, y, level+1);
        a[matrix[x-1][y]-'A'] = false;
    }
    
    //right
    if(x != c-1 && !a[matrix[x+1][y]-'A']){
        a[matrix[x+1][y]-'A'] = true;
        dfs(x+1, y, level+1);
        a[matrix[x+1][y]-'A'] = false;
    }
    
}

    
    
int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> r >> c;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> matrix[j][i];
        }
    }
    
    a[matrix[0][0]-'A'] = true;
    
    dfs(0,0, 1);
    
    cout << ans << '\n';
    
	return 0;
}