#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, n;
        I >> n;
        V<int> b(n), a(n, 0);
        F(i, 0, n - 1)
        {
            I >> b[i];
        }

        int m = INT_MAX;
        bool possible = true;
        F(i, 0, n - 1)
        {
            m = min(m, b[i]);

            if (b[i] >= 2 * m)
            {
                possible = false;
                break;
            }
        }

        O << (possible ? "yes" : "no") << '\n';
    }
    return 0;
}
