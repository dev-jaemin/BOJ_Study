#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;
    
    while(k != 0){
        string str;
        vector<int> v;
        vector<int> index;
        int tmp;
        
        for(int i=0;i<k;i++){
            cin >> tmp;
            v.push_back(tmp);
        }
        
        for(int i=0;i<k;i++){
            if(i < 6){
                index.push_back(0);
            }
            else{
                index.push_back(1);
            }
        }
        
        
        sort(index.begin(), index.end());
        
        
        
        do{
            for(int i=0;i<k;i++){
                if(index[i] == 0){
                    cout << v[i] << ' ';
                }
            }
            cout << '\n';
        }while(next_permutation(index.begin(), index.end()));
        
        cout << '\n';
        cin >> k;
    }
	
	return 0;
}