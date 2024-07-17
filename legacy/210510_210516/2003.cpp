#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m, sum, tmp, ans;
int arr[10010];


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    arr[0] = 0;
    
    for(int i=1;i<=n;i++){
        cin >> tmp;
        sum += tmp;
        
        arr[i] = sum;
    }
    
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[j] - arr[i] == m){
                ans++;
            }
        }
    }
    
    
    cout << ans << '\n';
	
	return 0;
}