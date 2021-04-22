#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, ans;
int arr[8], tmp[8];
bool used[8];

void Calculate(){
    int sum = 0;
    
    for(int i=0;i<n-1;i++){
        sum += abs(tmp[i] - tmp[i+1]);
    }
    
    if(ans < sum) ans = sum;
}


void dfs(int cnt){
    //갯수만큼 순열 탐색 완료하면 계산해본다.
    if(cnt >= n){
        Calculate();
        
        return;
    }
    
    //순열 탐색
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i] = true;
            tmp[cnt] = arr[i];
            dfs(cnt + 1);
            //다시 빠져나오면서 flag를 false로 한다.
            used[i] = false;
            
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dfs(0);
    
    cout << ans << '\n';
	
	return 0;
}