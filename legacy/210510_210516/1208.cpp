#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

long long n, s, tmp, ans;
vector<int> v1, v2;
vector<int> sum1, sum2;

vector<int> make_sum_list(vector<int> v){
    vector<int> ret;
    
    for(int i=1;i<=v.size();i++){
        vector<int> index;
        long long sum;
        
        for(int j=0;j<i;j++){
            index.push_back(1);   
        }
        for(int j=i;j<v.size();j++){
            index.push_back(0);
        }
        
        sort(index.begin(), index.end());

        
        do{
            sum = 0;
            
            for(int j=0;j<v.size();j++){
                if(index[j] == 1){
                    sum += v[j];
                }
            }
            
            ret.push_back(sum);
        }while(next_permutation(index.begin(), index.end()));
    }
    
    //ret.push_back(0);
    sort(ret.begin(), ret.end());
    
    return ret;
}

long long bisearch(vector<int> v, long long key){
    long long l = 0;
    long long r = v.size() - 1;
    long long ret = 0;
    long long mid;
    
    while(l<r){
        mid = (l+r)/2;
        
        //lower_bound
        if(key <= v[mid]){
            r = mid;
        }
        else{
            l = mid + 1;    
        }
    }
    
    for(int i=l;v[i] == key;i++){
        ret++;
    }
    
    return ret;
}


void count(){
    long long index1 = 0;
    long long index2 = sum2.size() - 1;
    
    while(index1 < sum1.size() && index2 >= 0){
        if(sum1[index1] + sum2[index2] == s){
            long long c1 = 1;
            long long c2 = 1;
            
            while(index1+c1 < sum1.size() && sum1[index1] == sum1[index1+c1]){
                c1++;
            }
            while(index2-c2 >= 0 && sum2[index2] == sum2[index2-c2]){
                c2--;
            }
            
            ans += c1*c2;
            
            index1 += c1;
            index2 -= c2;
        }
        
        else if(sum1[index1] + sum2[index2] > s){
            index2--;
        }
        else{
            index1++;
        }
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s;
    
    int n1 = n/2;
    int n2 = n - n/2;
    
    for(int i=0;i<n1;i++){
        cin >> tmp;
        v1.push_back(tmp);
    }
    
    for(int i=n1;i<n;i++){
        cin >> tmp;
        v2.push_back(tmp);
    }
    
    sum1 = make_sum_list(v1);
    sum2 = make_sum_list(v2);
    
    //test code
    /*
    for(int i=0;i<sum1.size();i++){
        cout << sum1[i] << ' ';
    }
    cout << '\n';
    
    for(int i=0;i<sum2.size();i++){
        cout << sum2[i] << ' ';
    }
    cout << '\n';
    */
    
    
    count();
    
    
    cout << (s == 0) ? ans -1 : ans << '\n';
    
	
	return 0;
}