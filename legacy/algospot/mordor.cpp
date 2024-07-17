#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

const int INT_MAX = numeric_limits<int>::max();
int c;



struct RMQ{
    int n;
    vector<int> rangeMin;
    
    RMQ(const vector<int>& array){
        n = array.size();
        rangeMin.resize(4*n);
        init(array, 0, n-1, 1);
    }
    
    int init(const vector<int>& array, int left, int right, int node){
        if(left == right) return rangeMin[node] = array[left];
        
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid+1, right, node*2+1);
        
        return rangeMin[node] = min(leftMin, rightMin);
    }
    
    //[nodeLeft, nodeRight] : node가 표현하는 범위
    int query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(right < nodeLeft || left > nodeRight){
            return INT_MAX;
        }
        //node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우 -> 그 안에서 최솟값은 구해져 있으니까 바로 종료 -> 재귀중인 다른 부분의 결과값이 나오면 최솟값 비교하면됌.
        if(left <= nodeLeft && nodeRight <= right){
            return rangeMin[node];
        }
        
        int mid = (nodeLeft + nodeRight) / 2;
        
        return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
    
    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }
    
    //원 배열에서 원소 수정이 일어났을 때 세그먼트 트리를 수정하는 함수
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
        //범위에 해당하지 않는경우 무시
        if(index < nodeLeft || index > nodeRight){
            return rangeMin[node];
        }
        
        //leaf노드까지 왔다면 수정
        if(nodeLeft == nodeRight){
            return rangeMin[node] = newValue;
        }
        
        //leaf노드까지 가는 길
        int mid = (nodeLeft + nodeRight) / 2;
        
        return rangeMin[node] = min(update(index, newValue, node*2, nodeLeft, mid), update(index, newValue, node*2+1, mid+1, nodeRight));
    }
    
    int update(int index, int newValue){
        return update(index, newValue, 1, 0, n-1);
    }
};

vector<int> reverse(vector<int> v){
    for(int i=0;i<v.size();i++){
        v[i] = -v[i];
    }
    
    return v;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> c;
    
    while(c--){
        int n, q, a, b;
        vector<int> h, minusH;
        
        
        cin >> n >> q;
        
        h.resize(n);
        for(int i=0;i<n;i++){
            cin >> h[i];
        }
        
        minusH = reverse(h);
        RMQ rmq1(h);
        RMQ rmq2(minusH);
        
        for(int i=0;i<q;i++){
            cin >> a >> b;
            
            int minHeight = rmq1.query(a, b);
            int maxHeight = rmq2.query(a, b) * (-1);
            
            //cout << "a:" << a << " b:" << b << '\n';
            //cout << "min:" << minHeight << " max:" << maxHeight << '\n';
            cout << maxHeight - minHeight << '\n';
        }
    }
	
	return 0;
}