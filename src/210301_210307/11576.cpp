#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>


using namespace std;

int a, b, m;
int c, jari;
long long deci;
stack<int> s;

void makeStack(long long n, int k){
    while(n / k > 0){
        s.push(n % k);
        n /= k;
    }
    s.push(n);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b >> m;
    
    for(int i=m-1; i>=0;i--){
        cin >> c;
        
        jari = 1;
        for(int j=1;j<=i;j++){
            jari *= a;
        }
        
        deci += c * jari;
    }
    
    makeStack(deci, b);
    
    
    printStack(s);
    
	
	return 0;
}