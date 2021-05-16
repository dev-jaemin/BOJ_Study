#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, s, tmp, sum, ans;
vector<int> v;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    
    for(int i=1;i<=n;i++){
        vector<int> index;
        
        for(int j=0;j<i;j++){
            index.push_back(1);   
        }
        for(int j=i;j<n;j++){
            index.push_back(0);
        }
        
        sort(index.begin(), index.end());

        
        do{
            sum = 0;
            
            for(int j=0;j<n;j++){
                if(index[j] == 1){
                    sum += v[j];
                }
            }
            
            if(sum == s) ans++;
        }while(next_permutation(index.begin(), index.end()));
    }
    
    
    cout << ans << '\n';
    
	
	return 0;
}