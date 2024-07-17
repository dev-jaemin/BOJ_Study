#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
pair<char, char> tree[300];
char c1, c2, c3;

void preorder(char i){
    if(i != '.' && i >= 'A' && i <= 'Z'){
        cout << i;
        preorder(tree[i].first);
        preorder(tree[i].second);
    }
}

void inorder(char i){
    if(i != '.' && i >= 'A' && i <= 'Z'){
        inorder(tree[i].first);
        cout << i;
        inorder(tree[i].second);
    }
}

void postorder(char i){
    if(i != '.' && i >= 'A' && i <= 'Z'){
        postorder(tree[i].first);
        postorder(tree[i].second);
        cout << i;
    }
}

int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    //making tree
    for(int i=0;i<n;i++){
        cin >> c1 >> c2 >> c3;
        
        tree[c1] = { c2,c3 };
    }
    
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
	
	return 0;
}