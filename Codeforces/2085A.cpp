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
    ll t, n, i, k;
    I >> t;
    while (t--)
    {
        string r, s;
        I >> n >> k >> s;

        r = s;

        reverse(all(r));

        char chMax = *max_element(all(s));
        char chMin = *min_element(all(s));

        if (s == r)
        {
            O << (k == 0 or chMax == chMin ? "no" : "yes") << '\n';
            continue;
        }

        F(i, 0, n - 1)
        {
            char c = r[i];
            if (s[i] < c)
            {
                break;
            }
            if (s[i] == c)
            {
                continue;
            }

            if (k == 0)
            {
                break;
            }

            r[i] = s[i];
            s[i] = c;

            --k;
        }

        O << (s < r ? "yes" : "no") << '\n';
    }
    return 0;
}
