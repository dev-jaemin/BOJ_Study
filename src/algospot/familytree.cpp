#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;


int c;
const int MAX_N = 100000;
int n, q;
vector<int> child[MAX_N];
//트리 번호와 일련번호 사이의 관계(트리 번호 : 문제에서 제시한 번호, 일련 번호 : 부모가 자식보다 숫자가 작도록 전위순회하면서 부여한 숫자)
int no2serial[MAX_N], serial2no[MAX_N];
//각 노드가 trip에 처음 등장하는 위치, 그리고 각 노드의 깊이
int locInTrip[MAX_N], depth[MAX_N];
//다음 일련번호
int nextSerial;


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
            return MAX_N;
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






//깊이가 d인 노드 here이하를 전위 탐색한다.
//trip은 일련번호로 이루어진 배열.
void traverse(int here, int d, vector<int>& trip){
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    
    nextSerial++;
    
    depth[here] = d;
    locInTrip[here] = trip.size();
    trip.push_back(no2serial[here]);
    
    for(int i=0;i<child[here].size();i++){
        traverse(child[here][i], d+1, trip);
        trip.push_back(no2serial[here]);
    }
}

//트리를 순회하며 각종 필요한 정보를 계산하고, RMQ 구간 트리를 만들어 반환한다.
RMQ* prepareRMQ(){
    nextSerial = 0;
    vector<int> trip;
    
    traverse(0, 0, trip);
    
    return new RMQ(trip);
}

//u와 v 사이의 거리를 계산한다.
int distance(RMQ* rmq, int u, int v){
    int lu = locInTrip[u];
    int lv = locInTrip[v];
    
    //cout << "lu : " << lu << " lv : " << lv << '\n';
    
    if(lu > lv) swap(lu, lv);
    
    int parentDepth = depth[serial2no[rmq->query(lu, lv)]];
    
    //cout << "du : " << depth[u] << " dv : " << depth[v] << '\n';
    return (depth[u] - parentDepth) + (depth[v] - parentDepth);
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> c;
    
    while(c--){
        
        
        cin >> n >> q;
        
        for(int i=1;i<n;i++){
            int parent;
            
            cin >> parent;
            child[parent].push_back(i);
        }
        
        RMQ* rmq = prepareRMQ();

        
        for(int i=0;i<q;i++){
            int a, b;
            cin >> a >> b;
        
            cout << distance(rmq, a, b) << '\n';
        }
        
    }
	
	return 0;
}