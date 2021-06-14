#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef struct{
    int x,y,r;
    vector<Circle*> childs;
}Circle;

typedef struct{
    vector<TreeNode*> childs;
}TreeNode;



int C, N;
vector<Circle> v;
vector<int> parent;



double distance(Circle& c1, Circle& c2){
    return sqrt(pow(c2.x-c1.y) + pow(c2.y-c1.y));
}

bool isContain(Circle& big, Circle& small){
    return distance(big, small) < big.r - small.r;
}

vector<int> makeParent(){
    vector<int> ret(N);
    
    //root의 부모는 없음
    ret[0] = 0;
    for(int i=1;i<N;i++){
        vector<int> ancestor;
        int minn = 1e10;
        int mini = 0;
            
        for(int j=0;j<N;j++){
            if(i==j) continue;
                
            if(v[i].r < v[j].r && isContain(v[j], v[i])){
                ancestor.push_back(j);
            }
        }
            
        for(int i=0;i<ancestor.size();i++){
            if(minn > ancestor[i]){
                minn = ancestor[i];
                mini = i;
            }
        }
            
        ret[i] = mini;
    }
    
    return ret;
}


TreeNode* makeTree(){
    vector<TreeNode*> nodes;
    
    for(int i=0;i<N;i++){
        nodes.push_back(new TreeNode());
    }
    
    for(int i=1;i<N;i++){
        nodes[parent[i]]->childs.push_back(nodes[i]);
    }
    
    return nodes[0];
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> C;
    
    while(C--){
        cin >> N;
        
        for(int i=0;i<N;i++){
            Circle c;
            
            cin >> c.x >> c.y >> c.r;
            
            v.push_back(c);
        }
        
        
        parent = makeParent();
        
        TreeNode* root = makeTree();
        
    }
	
	return 0;
}