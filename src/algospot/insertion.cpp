#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

typedef int KeyType;
typedef pair<Node*, Node*> NodePair;


int n;

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
}

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
        
        newNode.setLeft(sp.first);
        newNode.setRight(sp.second);
        
        return newNode;
    }
    else{
        if(root->key < newNode->key){
            root->setLeft(insert(root->left, newNode));
        }
        else{
            root->setRight(insert(root->right, newNode));
        }
    }
    
    return root;
}


Node* merge(Node* a, Node* b);


Node* erase(Node* root, KeyType key){
    if(root == NULL) return root;
    
    if(root->key < key){
        root->left(erase(root->left, key));
    }
    else if(root->key > key){
        root->right(erase(root->right, key));
    }
    else{
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	return 0;
}