#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;

vector<string> v[210];
int tmp_n;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    
    for(int i=1;i<=n;i++){
        string tmp_str;
        
        cin >> tmp_n;
        cin >> tmp_str;
        
        v[tmp_n].push_back(tmp_str);  
    }
    
    for(int i=1;i<=200;i++){
        for(int j=0;j<v[i].size();j++){
            cout << i << ' ' << v[i][j] << '\n';
        }
    }
    
    
	
	return 0;
}