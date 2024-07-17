#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int l, c;
bool ch[26];
bool visited[26];


//자음 모음 갯수 체크
bool chk(string s){
    int vowel = 0;
    int consonant = 0;
    
    for(int i=0;i<l;i++){
        
        switch(s[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel++;
                break;
            default:
                consonant++;
                break;
        }
        
        if(vowel >= 1 && consonant >= 2){
            return true;
        }
    }
    
    return false;
}

//dfs로 하나하나 탐색
void dfs(string s, int level, int prev){
    
    if(level == l){
        if(chk(s)){
            cout << s << '\n';
        }
        
        return;
    }
    
    for(int i=0;i<26;i++){
        if(ch[i] && !visited[i] && prev < i){
            visited[i] = true;
            s.push_back(i + 'a');
            dfs(s, level + 1, i);
            s.pop_back();
            visited[i] = false;
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> l >> c;
    char tmp;
    string str;
    
    for(int i=0;i<c;i++){
        cin >> tmp;
        ch[tmp - 'a'] = true;
    }
    
    dfs(str, 0, -1);
	
	return 0;
}