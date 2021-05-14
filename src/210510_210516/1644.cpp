#include <iostream>
#include <algorithm>
#include <vector>
#define N 4000000

using namespace std;

int n, s, sum, tmp, ans;
vector<int> arr;
bool prime[N]; // false : prime number

void make_prime(int n){
    prime[0] = true;
    prime[1] = true;
    
    for(int i=2;i*i<=n;i++){
        if(prime[i]) continue;
        
        for(int j=i*i;j<=n;j+=i){
            prime[j] = true;
        }
    }
    
    arr.push_back(0);
    
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            sum += i;
            arr.push_back(sum);
        }
    }
}




int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    make_prime(n);
    
    
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(n == arr[j] - arr[i]){
                ans++;
            }
        }
    }

    
    
    cout << ans << '\n';
	
	return 0;
}