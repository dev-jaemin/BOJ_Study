#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>


using namespace std;

int n, b;
char c;
stack<char> s;

char ascii(int n){
    if(n>=0 && n<=9) return (char)(n+48);
    else return (char)(n + 55); 
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> b;
    
    while(n != 0){
        s.push(ascii(n%b));
        n = n / b;
    }
    
    while(!s.empty()){
        c = s.top();
        cout << c;
        s.pop();
    }
    
    cout << '\n';
	
	return 0;
}