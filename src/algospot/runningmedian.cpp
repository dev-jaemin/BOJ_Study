#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

struct RNG{
    int seed, a, b;
    
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next(){
        int ret = seed;
        seed = (seed*(long long)a+b) % 20090711;
        return ret;
    }
};

int c;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> c;
    
    while(c--){
        long long ans = 0;
        int n,a,b;
        
        cin >> n >> a >> b;
        
        RNG rng(a, b);
        
        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0;i<n;i++){   
            if(maxHeap.size() == minHeap.size()){
                maxHeap.push(rng.next());
            }
            else{
                minHeap.push(rng.next());
            }
            
            //최대힙의 루트가 최소힙의 루트보다 큰 경우
            if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()){
                int minTop = minHeap.top();
                int maxTop = maxHeap.top();
                
                minHeap.pop();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(minTop);
            }
            
            ans += maxHeap.top() % 20090711;
        }
        
        cout << ans % 20090711 << '\n';
    }
    
	return 0;
}