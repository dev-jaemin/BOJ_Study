#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>


using namespace std;

int t, a, b;
int visited[10000];
int from[10000][2];
stack<char> ans;

int d(int k){
    return (k * 2) % 10000;
}

int s(int k){
    if(k == 0) return 9999;
    else return k-1;
}

int l(int k){
    int x = k / 1000; //1000의자리
    k = k % 1000;
    int y = k / 100; //100의자리
    k = k % 100;
    int z = k / 10; //10의자리
    k = k % 10; //1의자리
   
    
    return y * 1000 + z * 100 + k * 10 + x;
}

int r(int k){
    int x = k / 1000; //1000의자리
    k = k % 1000;
    int y = k / 100; //100의자리
    k = k % 100;
    int z = k / 10; //10의자리
    k = k % 10; //1의자리
   
    
    return k * 1000 + x * 100 + y * 10 + z;
}

void bfs(){
    queue<int> q;
    int front, d1, d2, d3, d4;
    
    q.push(a);
    visited[a] = 1;
    from[a][1] = -1; // 이후에 시작점을 찾기위해 -1로 둠
    
    while(!q.empty()){
        front = q.front();
        q.pop();
        
        if(front == b) break;
        
        d1 = d(front);
        d2 = s(front);
        d3 = l(front);
        d4 = r(front);
        
        if(visited[d1] == 0){
            q.push(d1);
            visited[d1] = visited[front] + 1;
            from[d1][0] = 'D';
            from[d1][1] = front;
        }
        
        if(visited[d2] == 0){
            q.push(d2);
            visited[d2] = visited[front] + 1;
            from[d2][0] = 'S';
            from[d2][1] = front;
        }
        
        if(visited[d3] == 0){
            q.push(d3);
            visited[d3] = visited[front] + 1;
            from[d3][0] = 'L';
            from[d3][1] = front;
        }
        
        if(visited[d4] == 0){
            q.push(d4);
            visited[d4] = visited[front] + 1;
            from[d4][0] = 'R';
            from[d4][1] = front;
        }
    }
}

void tracking(int k){
    if(from[k][1] == -1) return;
    
    ans.push(from[k][0]);
    tracking(from[k][1]);
}

void print_stack(){
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> a >> b;
        
        bfs();
        tracking(b);
        print_stack();
        cout << '\n';
        
        for(int i=0;i<10000;i++){
            visited[i] = 0;
            from[i][0] = 0;
            from[i][1] = 0;
        }
        
        
    }
	
	return 0;
}