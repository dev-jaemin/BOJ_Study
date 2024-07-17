#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int matrix[9][9];
int zero_n;
vector<pair<int, int>> zeros;

void print_matrix(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << matrix[j][i] << ' ';
        }
        
        cout << '\n';
    }
}

bool chk(pair<int, int> p, int n){
    int x = p.first;
    int y = p.second;
    bool hor[10];
    bool ver[10];
    bool square[10];
    vector<int> sq_hor;
    vector<int> sq_ver;
    
    for(int i=0;i<10;i++){
        hor[i] = false;
        ver[i] = false;
        square[i] = false;
    }
    
    for(int i=0;i<9;i++){
        hor[matrix[x][i]] = true;
        ver[matrix[i][y]] = true;
    }
    
    if(x%3==0){
        for(int i=0;i<3;i++){
            sq_hor.push_back(x+i);
        }
    }
    if(x%3==1){
        for(int i=-1;i<=1;i++){
            sq_hor.push_back(x+i);
        }
    }
    if(x%3==2){
        for(int i=-2;i<=0;i++){
            sq_hor.push_back(x+i);
        }
    }
    
    if(y%3==0){
        for(int i=0;i<3;i++){
            sq_ver.push_back(y+i);
        }
    }
    if(y%3==1){
        for(int i=-1;i<=1;i++){
            sq_ver.push_back(y+i);
        }
    }
    if(y%3==2){
        for(int i=-2;i<=0;i++){
            sq_ver.push_back(y+i);
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sq_ver[j] == x && sq_hor[i] == y){
                continue;
            }
            
            square[matrix[sq_hor[j]][sq_ver[i]]] = true;
        }
    }
    
    //가로, 세로, 사각형에 중복된 것이 있으면 실패
    if(hor[n]) return false;
    if(ver[n]) return false;
    if(square[n]) return false;
    
    return true;
}


bool chk2(pair<int, int> p, int n){
    int x = p.first;
    int y = p.second;
    vector<int> sq_hor;
    vector<int> sq_ver;
    
    for(int i=0;i<9;i++){
        if(n == matrix[i][y]){
            return false;
        }
    }
    
    for(int i=0;i<9;i++){
        if(n == matrix[x][i]){
            return false;
        }
    }
    
    if(x%3==0){
        for(int i=0;i<3;i++){
            sq_hor.push_back(x+i);
        }
    }
    else if(x%3==1){
        for(int i=-1;i<=1;i++){
            sq_hor.push_back(x+i);
        }
    }
    else{
        for(int i=-2;i<=0;i++){
            sq_hor.push_back(x+i);
        }
    }
    
    if(y%3==0){
        for(int i=0;i<3;i++){
            sq_ver.push_back(y+i);
        }
    }
    else if(y%3==1){
        for(int i=-1;i<=1;i++){
            sq_ver.push_back(y+i);
        }
    }
    else{
        for(int i=-2;i<=0;i++){
            sq_ver.push_back(y+i);
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            /*if(sq_ver[j] == x && sq_hor[i] == y){
                continue;
            }*/
            
            if(matrix[sq_hor[j]][sq_ver[i]] == n) return false;
        }
    }
    
    return true;
}



void dfs(int level, bool* success){
    if(*success == true) return;
    
    if(level == zero_n){
        print_matrix();
        *success = true;
        
        return;
    }
    
    for(int i=1;i<=9;i++){
        if(chk2(zeros[level], i)){
            matrix[zeros[level].first][zeros[level].second] = i;
            dfs(level+1, success);
            if(*success == true) return;
            matrix[zeros[level].first][zeros[level].second] = 0;
        }
    }
}



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> matrix[j][i];
            if(matrix[j][i] == 0){
                zeros.push_back({ j, i });
            }
        }
    }
    
    zero_n = zeros.size();
    
    bool success = false;
    dfs(0, &success);
    
	
	return 0;
}