#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        string s;
        I >> n >> s;
        i = count(all(s), '-');
        j = count(all(s), '_');

        if (n < 3 or i < 2 or j == 0)
        {
            O << "0\n";
            continue;
        }

        q = 0;
        F(k, 1, (i + 1) / 2)
        {
            q = max(q, k * j * (i - k));
        }

        O << q << '\n';
    }
    return 0;
}
