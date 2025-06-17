#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j;
    I >> t;
    while (t--)
    {
        string s;
        I >> s;
        n = s.size();
        q = 0;
        j = 0;
        F(i, 0, n - 1)
        {
            if (s[i] == '(')
            {
                ++j;
            }
            else
            {
                --j;

                if (j == 0)
                {
                    ++q;
                }
            }
        }

        O << (q > 1 ? "YES" : "NO") << '\n';
    }
    return 0;
}
