#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, p = "";
        cin >> s;
        int n = s.size();
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i - 1])
            {
                p = s.substr(i - 1, 2);
                break;
            }
        }

        if (!p.empty())
        {
            cout << p << '\n';
            continue;
        }

        for (int i = 2; i < n; ++i)
        {
            if (s[i] != s[i - 1] and s[i - 1] != s[i - 2] and s[i - 2] != s[i])
            {
                p = s.substr(i - 2, 3);
                break;
            }
        }

        if (!p.empty())
        {
            cout << p << '\n';
            continue;
        }

        cout << "-1\n";
    }
    return 0;
}
