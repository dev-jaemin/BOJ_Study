#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int t, n, m, k, answer;
int field[51][51] = {0,};
bool queued[51][51];

void bfs(int x, int y);

int main(int argc, char *argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> m >> n >> k;

        int x, y;

        while(k--){
            cin >> x >> y;
            field[x][y] = 1;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!queued[i][j] && field[i][j] == 1){
                    bfs(i, j);
                    answer++;
                }
                
            }
        }

        cout << answer << '\n';

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                queued[i][j] = false;
                field[i][j] = 0;
                answer = 0;
            }
        }
    }

    return 0;
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;

    q.push(make_pair(x, y));
    queued[x][y] = true;

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();

        int nextX = current.first + 1;
        int nextY = current.second;

        if(nextX < m && field[nextX][nextY] == 1 && !queued[nextX][nextY]){
            queued[nextX][nextY] = true;
            q.push(make_pair(nextX, nextY));
        }

        nextX = current.first - 1;
        nextY = current.second;

        if(nextX >= 0 && field[nextX][nextY] == 1 && !queued[nextX][nextY]){
            queued[nextX][nextY] = true;
            q.push(make_pair(nextX, nextY));
        }

        nextX = current.first;
        nextY = current.second - 1;

        if(nextY >= 0 && field[nextX][nextY] == 1 && !queued[nextX][nextY]){
            queued[nextX][nextY] = true;
            q.push(make_pair(nextX, nextY));
        }

        nextX = current.first;
        nextY = current.second + 1;

        if(nextY < n && field[nextX][nextY] == 1 && !queued[nextX][nextY]){
            queued[nextX][nextY] = true;
            q.push(make_pair(nextX, nextY));
        }
    }
}