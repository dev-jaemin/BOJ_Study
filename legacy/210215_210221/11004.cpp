#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, tmp, k;
vector<int> v;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    cout << v[k-1] << '\n';
	
	return 0;
}