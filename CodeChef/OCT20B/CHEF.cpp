#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long n, k, i, c = 0, a = 0, x = 0, days = 1;
        cin >> n >> k;
        vector<long> q(n);
        for (i = 0; i < n; ++i)
            cin >> q[i];
        for (i = 0; i < n; ++i)
        {
            if (q[i] >= k)
            {
                ++days;
                c = q[i] - k;
                if (i < n - 1)
                    q[i + 1] += c;
                q[i] = k;
            }
            else
            {
                c = 0;
                break;
            }
        }
        if (c > 0)
        {
            days += c / k;
        }
        cout << days << '\n';
    }
    return 0;
}