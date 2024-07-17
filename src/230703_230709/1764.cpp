#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<string> answer;

int main(int argc, char *argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string friend_name;
    set<string> friend_set;

    while (n--)
    {
        cin >> friend_name;

        friend_set.insert(friend_name);
    }

    while (m--)
    {
        string input;
        cin >> input;

        if (friend_set.find(input) != friend_set.end())
        {
            answer.push_back(input);
        }
    }

    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}