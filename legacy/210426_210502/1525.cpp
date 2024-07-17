#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>


using namespace std;

int ans;
string start;
string last = "123456789";
map<string, int> visited;

int zero_pos(string s){
    for(int i=0;i<s.length();i++){
        if(s[i] == '0') return i;
    }
    
    return -1;
}

string swap(string s, int a, int b){
    string ret = s;
    char tmp = ret[a];
    ret[a] = ret[b];
    ret[b] = tmp;
    
    return ret;
}

vector<string> branch(string s){
    vector<string> ret;
    
    int index = zero_pos(s);
    
    int up = index - 3;
    int down = index + 3;
    int left = index - 1;
    int right = index + 1;
    
    if(up >= 0){
        string up_swap = swap(s, index, up);
        
        
        ret.push_back(up_swap);
    }
    
    if(down < 9){
        string down_swap = swap(s, index, down);
        
        ret.push_back(down_swap);
    }
    
    if(index != 0 && index != 3 && index != 6){
        string left_swap = swap(s, index, left);
        
        ret.push_back(left_swap);
    }
    
    if(index != 2 && index != 5 && index != 8){
        string right_swap = swap(s, index, right);
        
        ret.push_back(right_swap);
    }
    
    return ret;
}


int bfs(){
    
    queue<string> q;
    string cur;
    
    q.push(start);
    visited.insert({start, 0});
    
    while(!q.empty()){
        cur = q.front();
        //cout << cur << '\n';
        q.pop();
        
        if(cur == "123456780"){
            return visited["123456780"];
        }
        
        vector<string> v = branch(cur);
        
        for(int i=0;i<v.size();i++){
            //방문하지 않은 경우
            //cout << v[i] << '\n';
            if(visited.find(v[i]) == visited.end()){
                visited.insert({ v[i], visited[cur] + 1 });
                q.push(v[i]);
            }
        }
    }
    
    return -1;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char tmp[9];
    
    for(int i=0;i<9;i++){
        cin >> tmp[i];
    }
    
    start = tmp;
    
    cout << bfs() << '\n';
	
	return 0;
}