#include <iostream>
#include <algorithm>
#include <vector>
#define N 4000000

using namespace std;

int n, s, e, sum, ans;
vector<int> arr;
vector<bool> prime; // false : prime number

void make_prime(){
    prime.resize(n+1, false);
    
    prime[0] = true;
    prime[1] = true;
    
    for(int i=2;i*i<=n;i++){
        if(prime[i]) continue;
        
        for(int j=i*i;j<=n;j+=i){
            prime[j] = true;
        }
    }
    
    //arr.push_back(0);
    
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            //sum += i;
            arr.push_back(i);
        }
    }
}




int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    make_prime();
    
    /* 무식하게 모든 경우를 체크 -> 시간초과
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(n == arr[j] - arr[i]){
                ans++;
            }
        }
    }
    */
    
    
    //두 포인터 사용
    //start가 가리키는 곳은 포함되고, end가 가리키는 곳은 포함 x
    while(1){
        if(sum >= n) sum -= arr[s++];
        else if(e == arr.size()) break;
        else sum += arr[e++];
        
        if(sum == n) {
            //cout << arr[s] << ' ' << arr[e-1] << ' ' << '\n';
            ans++;
        }

    }
    
    
    cout << ans << '\n';
	
	return 0;
}