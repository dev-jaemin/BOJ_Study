#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int n;
//int matrix[30][30];
char matrix[30][30];
bool visited[30][30];
vector<int> answer;
pair<int, int> start;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> matrix[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << matrix[i][j];
        }
        cout << '\n';
    }
	return 0;
}