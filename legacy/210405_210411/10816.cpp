#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m, tmp, c;
vector<int> v1;
vector<pair<int, int>> v2;


int search(int target){
    int l = 0;
    int r = v2.size()-1;
    int mid;
    
    while(l <= r){
        mid = (l + r) / 2;
        
        if(target == v2[mid].first){
            return v2[mid].second;
        }
        else if(target > v2[mid].first){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    return 0;
}



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        
        v1.push_back(tmp);
    }
    
    sort(v1.begin(), v1.end());

    
    //카드 갯수 세기
    int i, j;
    
    for(i=0;i<n;i=j){
        c = 1;
        
        for(j=i+1;v1[i]==v1[j];j++){
            c++;
        }
        
        //cout << v1[i] << ':' << c << '\n';
        v2.push_back({ v1[i],c });
    }

    
    cin >> m;
    
    while(m--){
        cin >> tmp;
        
        cout << search(tmp) << ' ';
    }
    
    cout << '\n';
	
	return 0;
}