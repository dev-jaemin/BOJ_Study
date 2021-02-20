#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
int tmp;
int arr[10001];


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> tmp;
        arr[tmp]++;
    }
    
    for(int i=1;i<=10000;i++){
        for(int j=0;j<arr[i];j++){
            cout << i << '\n';
        }
    }
    
	return 0;
}