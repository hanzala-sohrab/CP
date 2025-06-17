#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n >> k;
        string s;
        I >> s;

        ll c0 = 0, c1 = 0;
        F(i, 0, n - 1)
        {
            if (s[i] == '0')
            {
                ++c0;
            }
            else
            {
                ++c1;
            }
        }

        q = (n / 2 - k);

        if (c0 >= q and (c0 - q) % 2 == 0 and c1 >= q and (c1 - q) % 2 == 0)
        {
            O << "YES\n";
        }
        else
        {
            O << "NO\n";
        }
    }
    return 0;
}
