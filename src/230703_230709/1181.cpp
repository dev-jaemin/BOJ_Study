#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<string> v;

bool compare(string a, string b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }

    return a.size() < b.size();
}

int main(int argc, char *argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n--)
    {
        string s;

        cin >> s;

        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    string cur = "";
    for (int i = 0; i < v.size(); i++)
    {
        if (cur.compare(v[i]))
        {
            cout << v[i] << '\n';

            cur = v[i];
        }
    }

    return 0;
}