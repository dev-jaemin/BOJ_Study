#include <iostream>
#include <algorithm>


using namespace std;

int n, s, sum, tmp, ans;
int arr[100010];

bool chk(int i){
    for(int j=0;j<=n-i;j++){
        if(arr[j+i] - arr[j] >= s){
            return true;
        }
    }
    
    return false;
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
    
    //길이로 lower_bound하기
    int mid;
    int l = 1;
    int r = n;
    
    while(l <= r){
        mid = (l + r) / 2;
      
        //lower_bound
        if(chk(mid)){
            ans = mid; // r은 mid-1이라서 마지막으로 되는 것을 놓칠 수가 있음
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    
    
    cout << ans << '\n';
	
	return 0;
}