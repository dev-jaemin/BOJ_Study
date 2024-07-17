#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int t;
pair<int, int> answer[41];

pair<int, int> fibonacci(int n)
{
    if (n == 0)
    {

        return make_pair(1, 0);
    }
    else if (n == 1)
    {
        return make_pair(0, 1);
    }
    else if (answer[n] != make_pair(-1, -1))
    {
        return answer[n];
    }
    else
    {
        pair<int, int> ans = make_pair(fibonacci(n - 1).first + fibonacci(n - 2).first, fibonacci(n - 1).second + fibonacci(n - 2).second);
        answer[n] = ans;

        return ans;
    }
}

int main(int argc, char *argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < 41; i++)
    {
        answer[i] = make_pair(-1, -1);
    }

    while (t--)
    {
        int n;
        cin >> n;

        pair<int, int> ans = fibonacci(n);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}