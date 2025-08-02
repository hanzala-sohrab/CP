#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.ss != b.ss)
        return a.ss < b.ss;
    return a.ff > b.ff;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t;
    I >> t;
    while (t--)
    {
        int i;
        ll n, p, ans = 0;
        I >> n >> p;

        V<pair<int, int>> ba(n);
        F(i, 0, n - 1)
        {
            I >> ba[i].ff;
        }
        F(i, 0, n - 1)
        {
            I >> ba[i].ss;
        }

        sort(all(ba), comp);

        if (p <= ba[0].ss)
            ans = p * n;
        else
        {
            ans += p;
            --n;

            i = 0;

            while (n > 0 and i < ba.size())
            {
                ll f = ba[i].ff;
                ll s = ba[i].ss;
                if (p <= s)
                {
                    ans += p;
                    --n;
                }
                else
                {
                    ll m = min(n, f);
                    ans += m * s;
                    n -= m;
                }
                ++i;
            }
        }

        O << ans << '\n';
    }
    return 0;
}
