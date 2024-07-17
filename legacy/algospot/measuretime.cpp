#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

//펜윅 트리 구현
//A[]의 부분 합을 빠르게 구현할 수 있도록 한다.
struct FenwickTree{
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    
    //A[0..pos]의 부분합
    int sum(int pos){
        ++pos;
        int ret = 0;
        while(pos > 0){
            ret += tree[pos];
            //최종비트 지우기
            pos &= (pos-1);
        }
        
        return ret; 
    }
    
    void add(int pos, int val){
        ++pos;
        while(pos < tree.size()){
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int c;

long long countMoves(const vector<int>& A){
    FenwickTree tree(1000000);
    long long ret = 0;
    
    for(int i=0;i<A.size();i++){
        ret += tree.sum(999999) - tree.sum(A[i]);
        
        tree.add(A[i], 1);
    }
    
    return ret;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> c;
    
    while(c--){
        int n;
        cin >> n;
        vector<int> A(n);
        
        for(int i=0;i<n;i++){
            cin >> A[i];
        }
        
        cout << countMoves(A) << '\n';
    }
	
	return 0;
}