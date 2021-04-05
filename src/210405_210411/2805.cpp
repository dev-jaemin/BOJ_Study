#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
long long m, h, total, l, r, mid;
vector<long long> trees;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> h;
        trees.push_back(h);
        if(h > r) r = h;
    }
    
    l = 1;
    
    while(l < r){
        mid = (r + l) / 2;
        total = 0;
        
        for(int i=0;i<n;i++){
            if(trees[i] - mid > 0) total += trees[i] - mid;
        }
        
        if(total < m){
            r = mid;
        }
        else if(total > m){
            l = mid + 1;
        }
        else{
            break;
        }
    }
    
    cout << mid << '\n';
    
	
	return 0;
}