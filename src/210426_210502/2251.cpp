#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

typedef struct{
    int a;
    int b;
    int c;
} state;

int A, B, C;
bool visited[201][201][201];
bool ans[201];

state new_state(int a, int b, int c){
    state ret;
    ret.a = a;
    ret.b = b;
    ret.c = c;
    
    return ret;
}

vector<state> next_state(state now){
    vector<state> ret;
    
    //B->A
    if(now.a + now.b < A){
        ret.push_back(new_state(now.a+now.b, 0, now.c));
    }
    else{
        ret.push_back(new_state(A, now.a+now.b-A, now.c));
    }
    //C->A
    if(now.a + now.c < A){
        ret.push_back(new_state(now.a+now.c, now.b, 0));
    }
    else{
        ret.push_back(new_state(A, now.b, now.a+now.c-A));
    }
    //A->B
    if(now.a + now.b < B){
        ret.push_back(new_state(0, now.a+now.b, now.c));
    }
    else{
        ret.push_back(new_state(now.a+now.b-B, B, now.c));
    }
    //C->B
    if(now.b + now.c < B){
        ret.push_back(new_state(now.a, now.c+now.b, 0));
    }
    else{
        ret.push_back(new_state(now.a, B, now.b+now.c-B));
    }
    
    //A->C
    ret.push_back(new_state(0, now.b, now.a+now.c));
    //B->C
    ret.push_back(new_state(now.a, 0, now.b+now.c));
    
    
    return ret;
}

void bfs(){
    queue<state> q;
    
    q.push(new_state(0, 0, C));
    visited[0][0][C] = true;
    
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        
        vector<state> v = next_state(cur);
        
        for(int i=0;i<v.size();i++){
            if(!visited[v[i].a][v[i].b][v[i].c]){
                q.push(v[i]);
                visited[v[i].a][v[i].b][v[i].c] = true;
            }
        }
    }
}

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> C;
    
    bfs();
    
    for(int i=0;i<=200;i++){
        for(int j=0;j<=200;j++){
            if(visited[0][i][j]){
                ans[j] = true;
            }
        }
    }
    
    for(int i=0;i<=200;i++){
        if(ans[i]) cout << i << ' ';
    }
    cout << '\n';
	
	return 0;
}