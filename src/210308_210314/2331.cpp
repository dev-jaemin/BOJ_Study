#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

long long a, p, i, tmp;
vector<long long> v, result;
long long start, now, answer;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> p;
    
    now = a;
    
    result.push_back(a);
    answer = -1;
    while(answer == -1){
        stack<long long> jari;
        
        for(i=0;now>0;i++){
            jari.push(now%10);
            now /= 10;
        }
        
        while(!jari.empty()){
            tmp = 1;
            
            for(int i=0;i<p;i++){
                tmp *= jari.top();
            }
            
            now += tmp;
            jari.pop();
        }
        
        for(int i=0;i<result.size();i++){
            if(result[i] == now){
                start = now;
                answer = i;
                break;
            }         
        }
        
        result.push_back(now);
    }
    
    cout << answer << '\n';
    
	
	return 0;
}