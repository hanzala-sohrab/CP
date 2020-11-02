#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, p[n], pos[n + 1];
        for (i = 0; i < n; ++i)
            cin >> p[i], pos[p[i]] = i;
        string ans;
        int l = n, r = 0;
        for (int m = 1; m <= n; ++m)
        {
            r = max(r, pos[m]);
            l = min(l, pos[m]);
            if (r - l + 1 != m)
                ans += "0";
            else
                ans += "1";            
        }
        cout << ans << '\n';
    }
    return 0;
}