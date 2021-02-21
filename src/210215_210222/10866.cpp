#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>


using namespace std;

int n, k, tmp;
string command;
deque<int> d;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    while(n--){
        cin >> command;
        
        
        if(command == "push_front"){
            cin >> k;
            d.push_front(k);
        }
        else if(command == "push_back"){
            cin >> k;
            d.push_back(k);
        }
        else if(command == "pop_front"){
            if(d.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = d.front();
            cout << tmp << '\n';
            d.pop_front();
        }
        else if(command == "pop_back"){
            if(d.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = d.back();
            cout << tmp << '\n';
            d.pop_back();
        }
        else if(command == "front"){
            if(d.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = d.front();
            cout << tmp << '\n';
        }
        else if(command == "back"){
            if(d.empty() == 1){
                cout << -1 << '\n';
                continue;
            }
            tmp = d.back();
            cout << tmp << '\n';
        }
        else if(command == "empty"){
            cout << d.empty() << '\n';
        }
        else if(command == "size"){
            cout << d.size() << '\n';
        }
        else break;
        
    }
	
	return 0;
}