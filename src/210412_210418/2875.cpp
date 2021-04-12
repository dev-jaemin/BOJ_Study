#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m, k, intern_n, intern_m, max_team, answer;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    if(n > 2*m){
        max_team = m;
        intern_n = n - 2*m;
        intern_m = 0;
    }
    else{
        max_team = n / 2;
        intern_m = m - n / 2;
        intern_n = 0;
    }
    
    //팀짜고 남는 사람들보다 k가 클 경우
    while(k > intern_m + intern_n){
        max_team--;
        intern_m++;
        intern_n = intern_n + 2;
    }
    
    cout << max_team << '\n';
	
	return 0;
}