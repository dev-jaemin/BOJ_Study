#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>


using namespace std;

int n;
stack<int> s;
string inputs;
char cur, nextt, tmp;
long long answer;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> inputs;
    
    for(int i=0;i<inputs.length()-1;i++){
        cur = inputs[i];
        nextt = inputs[i+1];
        
        if(cur == '(' && nextt == '('){
            s.push(1);
        }
        else if(cur == '(' && nextt ==')'){
            answer += s.size();
            i++;
        }
        else if(cur == ')'){
            s.pop();
            answer++;
        }
        else{
            cout << "error\n";
        }
        //cout << "size : " << s.size() << '\n';
    }
    
    cout << answer+1 << '\n';
	
	return 0;
}