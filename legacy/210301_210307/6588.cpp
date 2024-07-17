#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
bool isPrime[1000100]; // true : not prime, false : prime
bool success;

void makePrime(bool p[]){
    for(int i=2;i<=1000000;i++){
        isPrime[i] = true;
    }
    
    for(long long i=2;i*i<=1000000;i++){
        if(!isPrime[i]) continue;
        for(long long j = i*i;j<=1000000;j+=i){
            isPrime[j] = false;
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    makePrime(isPrime);
    
    while(n != 0){
        success = false;
        for(int i=3;i<=n-3;i++){
            if(i%2 == 0) continue;
            if(isPrime[i] && isPrime[n-i]){
                cout << n << " = " << i << " + " << n-i << '\n';
                success = true;
                break;
            }
        }
        
        if(!success) cout << "Goldbach's conjecture is wrong.\n";

        cin >> n;
    }
	
	return 0;
}