#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>


using namespace std;

typedef int KeyType;

struct Node{
    KeyType key;
    
    int priority, size;
    
    Node *left, *right;
    
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){}
    
    void setLeft(Node* newLeft){ left = newLeft; calcSize(); }
    void setRight(Node* newRight){ right = newRight; calcSize(); }
    
    void calcSize(){
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key){
    if(root == NULL){
        return NodePair(NULL, NULL);
    }
    
    
    if(root->key < key){
        NodePair rs = split(root->right, key);
        
        root->setRight(rs.first);
        
        return NodePair(root, rs.second);
    }
    
    NodePair ls = split(root->left, key);
    
    root->setLeft(ls.second);
    
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* newNode){
    if(root == NULL){
        return newNode;
    }
    
    if(root->priority < newNode->priority){
        NodePair sp = split(root, newNode->key);
        
        newNode->setLeft(sp.first);
        newNode->setRight(sp.second);
        
        return newNode;
    }
    else{
        if(root->key <= newNode->key){
            root->setRight(insert(root->right, newNode));
        }
        else{
            root->setLeft(insert(root->left, newNode));
        }
    }
    
    return root;
}


Node* merge(Node* a, Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    if(a->priority < b->priority){
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}


Node* erase(Node* root, KeyType key){
    if(root == NULL) return root;
    
    if(root->key < key){
        root->setLeft(erase(root->left, key));
    }
    else if(root->key > key){
        root->setRight(erase(root->right, key));
    }
    else{
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    
    return root;
}

Node* kth(Node* root, int k){
    int leftSize = 0;
    
    if(root->left != NULL) leftSize = root->left->size;
    
    if(k<=leftSize) return kth(root->left, k);
    if(leftSize == k - 1){
        return root;
    }
    else{
        return kth(root->right, k - leftSize - 1);
    }
    
}



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int c;
    cin >> c;

    while(c--){
        int n = 0;
        cin >> n;
        
        vector<int> shifted(n);
        vector<int> ans(n);
        Node* root = NULL;
        
        for(int i=0;i<n;i++){
            cin >> shifted[i];
            
            root = insert(root, new Node(i+1));
        }
        
        for(int i = n-1; i>=0; i--){
            int larger = shifted[i];
            Node* k = kth(root, i+1-larger);
            ans[i] = k->key;
            root = erase(root, k->key);
        }
        for(int i=0;i<n;i++) cout << ans[i] << ' ';
        cout << '\n';
        
    }
    
	
	return 0;
}