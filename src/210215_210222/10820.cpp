#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

int n;
string str;
int answer[4];

void check(char c){
    if(c>=48 && c<=57) answer[2]++;
    else if(c>=97 && c<=122) answer[0]++;
    else if(c>=65 && c<=90) answer[1]++;
    else if(c==32) answer[3]++;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, str);
    
    while(str != "\0"){
        
        for(int i=0;i<str.length();i++){
            check(str[i]);
        }
        
        for(int i=0;i<=3;i++){
            cout << answer[i] << ' ';
        }
        cout << '\n';
        
        memset(answer, 0, sizeof(answer));
        
        getline(cin, str);
    }
	
	return 0;
}