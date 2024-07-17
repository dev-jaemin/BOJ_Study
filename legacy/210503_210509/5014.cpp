#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int f, s, g, u, d;
int visited[1000010];


void bfs(){
    queue<int> q;
    int cur;
    
    q.push(s);
    visited[s] = 1;
    
    while(!q.empty()){
        cur = q.front();
        q.pop();
        
        if(cur == g){
            break;
        }
        
        if(!visited[cur+u] && cur+u <= f){
            visited[cur+u] = visited[cur] + 1;
            q.push(cur+u);
        }
        
        if(!visited[cur-d] && cur-d >= 1){
            visited[cur-d] = visited[cur] + 1;
            q.push(cur-d);
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> f >> s >> g >> u >> d;
    
    if(s == g){
        cout << "0\n";
        return 0;
    }
    else if(s > g){
        if(d == 0){
            cout << "use the stairs\n";
            
            return 0;
        }
        
    }
    else{
        if(u == 0){
            cout << "use the stairs\n";
            
            return 0;
        }
    }
    
    bfs();
    
    if(visited[g] == 0){
        cout << "use the stairs\n"; 
    }
    else{
        cout << visited[g]-1 << '\n';
    }
    
    
	
	return 0;
}