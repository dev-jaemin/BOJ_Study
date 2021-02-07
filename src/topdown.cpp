#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
int cache[1010][1010];


int rec(int a, int b){
    if() return 1;
    
    int& ret = cache[a][b];
    
    if(ret != -1) return ret;
    
    return ret;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    
	
	return 0;
}