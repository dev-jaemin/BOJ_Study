#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char board[50][50];
int min_answer = 1000000000;

int getShouldChangeNum(pair<int, int> start)
{
    char left_top = board[start.first][start.second];
    char inverted_left_top = board[start.first][start.second] == 'B' ? 'W' : 'B';

    int should_change = 0;
    int inverted_should_change = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char cur = board[start.first + i][start.second + j];

            if ((i + j) % 2 == 0 && cur != left_top)
            {
                should_change++;
            }
            else if ((i + j) % 2 != 0 && cur == left_top)
            {
                should_change++;
            }

            if ((i + j) % 2 == 0 && cur != inverted_left_top)
            {
                inverted_should_change++;
            }
            else if ((i + j) % 2 != 0 && cur == inverted_left_top)
            {
                inverted_should_change++;
            }
        }
    }

    return min(should_change, inverted_should_change);
}

int main(int argc, char *argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            min_answer = min(min_answer, getShouldChangeNum(make_pair(i, j)));
        }
    }

    cout << min_answer << '\n';

    return 0;
}