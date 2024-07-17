#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
//초기화를 잘 하자.
using namespace std;

typedef struct Circle{
    int x,y,r;
    vector<Circle*> children;
}Circle;

typedef struct TreeNode{
    vector<TreeNode*> children;
}TreeNode;



int C, N, longest;



double distance(Circle& c1, Circle& c2){
    return sqrt(pow(c1.x-c2.x, 2) + pow(c1.y-c2.y, 2));
}

bool isContain(Circle& big, Circle& small){
    return distance(big, small) < big.r - small.r;
}

//parent배열 만들기
vector<int> makeParent(vector<Circle> v){
    vector<int> ret(N);
    
    //root의 부모는 없음
    ret[0] = -1;
    for(int i=1;i<N;i++){
        vector<int> ancestor;
        int minn = 1e9;
        int mini = 0;
            
        for(int j=0;j<N;j++){
            if(i==j) continue;
                
            if(v[i].r < v[j].r && isContain(v[j], v[i])){
                ancestor.push_back(j);
            }
        }
        
            
        for(int i=0;i<ancestor.size();i++){
            if(minn > v[ancestor[i]].r){
                minn = v[ancestor[i]].r;
                mini = ancestor[i];
            }
        }
            
        ret[i] = mini;
    }
    
    return ret;
}


TreeNode* makeTree(vector<int>& parent){
    vector<TreeNode*> nodes;
    
    for(int i=0;i<N;i++){
        nodes.push_back(new TreeNode());
    }
    
    for(int i=1;i<N;i++){
        nodes[parent[i]]->children.push_back(nodes[i]);
    }
    
    return nodes[0];
}


int height(TreeNode* root){
    vector<int> heights;
    for(int i=0;i<root->children.size();i++){
        heights.push_back(height(root->children[i]));
    }
    
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    
    if(heights.size() >= 2){
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
    }
    
    
    return heights.back() + 1;
}

int solve(TreeNode* root){
    longest = 0;
    
    int h = height(root);
    return max(longest, h);
}

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> C;
    
    while(C--){
        N = 0;
        longest = 0;
        
        vector<Circle> v;
        vector<int> parent; //각 원의 parent가 누군지에 대한 정보가 들어있음.
        
        cin >> N;
        
        for(int i=0;i<N;i++){
            Circle c;
            
            cin >> c.x >> c.y >> c.r;
            
            v.push_back(c);
        }
        
        
        parent = makeParent(v);
        
        TreeNode* root = makeTree(parent);

        cout << solve(root) << '\n';
        
    }
	
	return 0;
}