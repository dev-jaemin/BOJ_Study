#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, bs, maxx;
long long tmp;
vector<pair<long long, int>>v;
vector<long long> inputs;

int bsearch(long long key){
    int start = 0;
    int end = v.size() - 1;
    int mid;
    
    while(start <= end){
        mid = (start + end) / 2;
        
        if(v[mid].first == key){
            return mid;
        }
        else if(v[mid].first > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    
    return -1;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        inputs.push_back(tmp);
    }
    
    sort(inputs.begin(), inputs.end());
    
    for(int i=0;i<n;i++){
        tmp = inputs[i];
        
        bs = bsearch(tmp);
        
        if(bs == -1){
            v.push_back({ tmp, 1 });
        }
        else{
            v[bs].second++;
        }
    }
    
    maxx = 0;
    
    for(int i=1;i<v.size();i++){
        if(v[i].second > v[maxx].second){
            maxx = i;
        }
    }
    
    cout << v[maxx].first << '\n';
	
	return 0;
}