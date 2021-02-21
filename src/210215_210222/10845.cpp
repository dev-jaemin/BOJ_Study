#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int n, k, tmp;
string command;
queue<int> q;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while(n--){
        cin >> command;
        
        
        if(command == "push"){
            cin >> k;
            q.push(k);
        }
        else if(command == "pop"){
            if(q.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = q.front();
            cout << tmp << '\n';
            q.pop();
        }
        else if(command == "front"){
            if(q.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = q.front();
            cout << tmp << '\n';
        }
        else if(command == "back"){
            if(q.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = q.back();
            cout << tmp << '\n';
        }
        else if(command == "empty"){
            cout << q.empty() << '\n';
        }
        else if(command == "size"){
            cout << q.size() << '\n';
        }
        else break;
        
    }
	
	return 0;
}