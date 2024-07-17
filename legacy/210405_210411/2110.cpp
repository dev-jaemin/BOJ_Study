#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, c;
long long tmp, l, r, maxx, mid, answer;
vector<long long> houses;

long long search(long long target){
    long long leftt, rightt, midd;
    
    leftt = 0;
    rightt = n-1;
    
    while(leftt <= rightt){
        midd = (leftt + rightt) / 2;
        
        if(target == houses[midd]){
            return midd;
        }
        else if(target > houses[midd]){
            leftt = midd + 1;
        }
        else{
            rightt = midd - 1;
        }
    }
    
    return -1;
}


bool chk(long long d){
    
    long long cnt = 1;
    long long prev = houses[0];
    
    for(int i=1;i<n;i++){
        if(houses[i] - prev >= d){
            cnt++;
            prev = houses[i];
        }
    }
    
    if(cnt >= c) return true;
    return false;
    
    //처음에 짰던 실패코드. chk(d)함수를 가장 인접한 거리가 "정확히" d인지를 체크했다.
    /*
    for(long long first=0;first<n;first++){
        long long cnt = 2;
        long long second = search(houses[first]+d);
        
        if(second != -1){
            for(int i=first-1;i>=0;i--){
                if(houses[first] - houses[i] >= d){
                    cnt++;
                    first = i;
                }
            }
            
            for(int i=second+1;i<n;i++){
                if(houses[i] - houses[second] >= d){
                    cnt++;
                    second = i;
                }
            }
            
            if(cnt >= c)return true;
        }  
        
        
    }
    
    return false;
    */
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> c;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        houses.push_back(tmp);
        
        if(maxx < tmp){
            maxx = tmp;
        }
    }
    
    sort(houses.begin(), houses.end());
    
    l = 1;
    r = maxx - houses[0];
    
    while(l <= r){
        mid = (l + r) / 2;
        
        if(chk(mid)){
            answer = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
	
    cout << answer << '\n';

    
	return 0;
}