#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>


using namespace std;

int n;
list<char> str;

string original;
string command;

void print(list<char> l){
    for(list<char>::iterator it = l.begin(); it != l.end(); it++){
        cout << *it;
    }
    cout << '\n';
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> original;
    
    for(int i=0;i<original.length();i++){
        str.push_back(original[i]);
    }
    
    cin >> n;
    cin.ignore();
    
    list<char>::iterator iter = str.end();
    
    while(n--){
        getline(cin, command);
        
        if(command[0] == 'L'){
            if(iter != str.begin()) iter--;
        }
        else if(command[0] == 'D'){
            if(iter != str.end()) iter++;
        }
        else if(command[0] == 'B'){
            if(iter != str.begin()){
                iter = str.erase(--iter);
            }
        }
        else{
            str.insert(iter, command[2]);
        }
    }
    
    print(str);
    
	
	return 0;
}