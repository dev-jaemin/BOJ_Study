#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string str;

// dp[k] : 앞에서 (k-1)번째 자리가 마지막일 때, 해석가능한 경우의 수
// 문자열은 index가 0부터 시작함. 혼동하지 않기 위해 이번 문제만 dp[0] 부터 시작. 
int dp[5010]; 

//1~26이면 return 1, 나머진 return 0
int IsAlphabet(int start){
    string n = str.substr(start, 2);
    
    if(n[0] == '0') return 0;
    else if(n[0] == '1') return 1;
    else if(n[0] == '2'){
        switch(n[1]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6': return 1;
            default:
                return 0;
        }
    }
    else return 0;
}


//한 자리수를 검사할 때, 0인지 아닌지를 판단.(0은 대응하는 알파벳이 없으므로)
int IsNatural(int l){
    return str[l] != '0' ? 1 : 0; 
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str;
    
    n = str.length();
    
    dp[0] = IsNatural(0); // 0인지 아닌지만 판단
    dp[1] = dp[0] * IsNatural(1) + IsAlphabet(0); // 첫째자리|둘째자리로 해석하는 경우의 수 + 두 자리로 해석하는 경우의 수
    
    for(int i=2;i<n;i++){
        dp[i] = (dp[i-1] * IsNatural(i) + dp[i-2] * IsAlphabet(i-1)) % 1000000; // 직전항에 한자리 수를 더한것으로 해석하는 경우의 수 + 뒤의 두 자리 수를 한번에 알파벳으로 해석하는 경우의 수
    }
    
    cout << dp[n-1] << '\n';

    
	return 0;
}