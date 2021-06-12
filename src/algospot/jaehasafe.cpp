#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int c, n, ans;
string tmp1, tmp2;
bool flag;

//kmp알고리즘 개량 버젼
vector<int> getPartialMatch(const string& N){
    int Nsize = N.size();
    vector<int> pi(Nsize, 0);
    
    //kmp로 자기자신을 찾는다.
    //N에서 N을 찾는다. begin=0이면 자기자신을 찾아버리기 때문에 1로 시작한다.
    int begin = 1, matched = 0;
    
    while(begin + matched < Nsize){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else{
            if(matched == 0){
                ++begin;
            }
            else{
                //이걸 계산할 때면 pi[matched - 1]은 항상 계산되어있음
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    
    return pi;
}

//kmp알고리즘 오리지널 버전. 알고리즘은 똑같음.
vector<int> kmpSearch(const string& H, const string& N){
    int Hsize = H.size();
    int Nsize = N.size();
    int matched = 0;
    
    vector<int> pi = getPartialMatch(N);
    vector<int> ret;
    
    for(int i=0;i<Hsize;i++){
        
        while(matched > 0 && H[i] != N[matched]){
            matched = pi[matched - 1];
        }
        
        if(H[i] == N[matched]){
            matched++;
            
            if(matched == Nsize){
                ret.push_back(i - Nsize + 1);
                matched = pi[matched - 1];
            }
        }
    }
    
    return ret;
}

int shifts(const string& original, const string& target){
    return kmpSearch(original + original, target)[0];
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> c;
    
    while(c--){
        cin >> n;
        ans = 0;
        flag = false;

        cin >> tmp1;
        
        for(int i=0;i<n;i++){
            cin >> tmp2;
            
            
            if(flag) ans += shifts(tmp1, tmp2);
            else ans += shifts(tmp2, tmp1);
            tmp1 = tmp2;
            flag = !flag;
        }
        
        cout << ans << '\n';
    }
	
	return 0;
}