#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, s, sum, tmp, ans;
int arr[100010];

int chk(int i){
    int maxx = 0;
    
    for(int j=0;j<n-i;j++){
        maxx = max(maxx, arr[j+i] - arr[j]);
    }
    
    return maxx;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    arr[0] = 0;
    
    for(int i=1;i<=n;i++){
        cin >> tmp;
        sum += tmp;
        
        arr[i] = sum;
    }
    
    int mid, key;
    int l = 0;
    int r = n;
    
    while(l <= r){
        mid = (l + r) / 2;
        
        key = chk(mid);
        
        if(key == s){
            ans = mid;
            break;
        }
        else if(key < s){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    
    cout << ans << '\n';
	
	return 0;
}