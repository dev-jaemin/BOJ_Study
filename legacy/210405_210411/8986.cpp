#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


vector<long long> x;
long long n;


long long f(long long d){
    long long ret = 0;
    
    for(int i=0;i<x.size();i++){
        ret += abs(d*i - x[i]);
    }
    
    return ret;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long l, r, p, q, ans;
	
    cin >> n;
    x.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    
    l = 1;
    r = 1e9;
    
    while(l + 3 <= r){
        
        //l*2/3 + r/3보다 아래가 훨씬 빠르다.(이렇게 하면 시간초과 뜨는데 요건 안뜨네요...)
        p = (l*2 + r)/3;
        q = (l + r*2)/3;
        
        if(f(p) > f(q)){
            l = p;
        }
        else{
            r = q;
        }
    }
    
    ans = 1e18;
    
    for(int i=l;i<=r;i++){
        ans = min(ans, f(i));
    }
    
    cout << ans;
    
	return 0;
}