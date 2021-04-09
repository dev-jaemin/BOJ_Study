#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m, tmp;
vector<int> v;

/*
int search(int target){
    int l = 0;
    int r = n-1;
    int mid;
    
    while(l <= r){
        mid = (l + r) / 2;
        
        if(target == v[mid]){
            return 1;
        }
        else if(target > v[mid]){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    return 0;
}
*/


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    cin >> m;
    
    while(m--){
        cin >> tmp;
        
        //cout << search(tmp) << ' ';
        cout << binary_search(v.begin(), v.end(), tmp) << ' ';
    }
    
    cout << '\n';
	
	return 0;
}