#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>


using namespace std;

int n, k, tmp;
string command;
stack<int> s;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while(n--){
        cin >> command;
        
        
        if(command == "push"){
            cin >> k;
            s.push(k);
        }
        else if(command == "pop"){
            if(s.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = s.top();
            cout << tmp << '\n';
            s.pop();
        }
        else if(command == "top"){
            if(s.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = s.top();
            cout << tmp << '\n';
        }
        else if(command == "empty"){
            cout << s.empty() << '\n';
        }
        else if(command == "size"){
            cout << s.size() << '\n';
        }
        else break;
        
    }
	
	return 0;
}