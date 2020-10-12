#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> a(n);
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        if (!(n & 1) and !(n & (n - 1)))
        {
            cout << "-1\n";
            continue;
        }
        string o = "2 3 1 ";
        for (i = 4; i <= n; ++i)
        {
            if (!(i & 1) and !(i & (i - 1)))
            {
                o += to_string(i + 1) + " " + to_string(i) + " ";
                ++i;
            }
            else
                o += to_string(i) + " ";
        }
        cout << o << '\n';
    }
    return 0;
}