#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m;
int cur_n, cur_m;
long long ans;
bool sw;

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    cur_n = 1;
    cur_m = 1;
    
    
    switch(n){
        case 1:
            cout << 1 << '\n';
            break;
        case 2:
            if(m <= 6){
                cout << (m+1)/2 << '\n';    
            }
            else{
                cout << 4 << '\n';
            }
            break;
        default:
            if(m < 5){
                cout << m << '\n';
            }
            else if(m == 5){
                cout << 4 << '\n';
            }
            else{
                cout << m-2 << '\n';
            }
    }
    
	
	return 0;
}