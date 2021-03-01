#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, tmp;

queue<int> q;



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    cout << '<';
    
    while(q.size() > 1){
        for(int i=0;i<k-1;i++){
            tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        
        tmp = q.front();
        cout << tmp << ", ";
        q.pop();
    }
    
    tmp = q.front();
    
    cout << tmp << ">\n";
    
    
	
	return 0;
}