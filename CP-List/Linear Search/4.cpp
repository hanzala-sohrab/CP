#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int i, j = -1, k = -1, l = s.size();
        bool f = true;
        for (i = 0; i < l; ++i)
            if (s[i] == '1')
            {
                j = i;
                break;
            }
        if (j == -1)
        {
            cout << "NO\n";
            continue;
        }
        for (i = l - 1; i > j; --i)
            if (s[i] == '1')
            {
                k = i;
                break;
            }
        for (i = j; i <= k; ++i)
            if (s[i] == '0')
            {
                f = false;
                break;
            }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}