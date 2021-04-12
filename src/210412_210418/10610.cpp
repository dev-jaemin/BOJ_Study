#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

string n;
int arr[100010];

bool compare(int a, int b){
    return a > b;
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, n);
    
    int num = 0;
    bool zero = false;
    
    for(int i=0;i<n.size();i++){
        if(n[i] == '0') {
            zero = true;
        }
        num += (n[i] - 48);
        arr[i] = n[i] - 48;
    }
    
    if(zero){
        if(num%3 == 0){
            sort(arr, arr+n.size(), compare);
            for(int i=0;i<n.size();i++){
                cout << arr[i];
            }
            cout << '\n';
        }
        else{
            cout << -1 << '\n';    
        }
    }else{
        cout << -1 << '\n';
    }
	
	return 0;
}