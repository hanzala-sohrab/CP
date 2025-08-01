#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define pb push_back

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, j, n;

        I >> n;

        V<int> a(n), b(n);

        F(i, 0, n - 1)
        {
            I >> a[i] >> b[i];
        }

        V<int> res;

        F(i, 0, n - 1)
        {
            F(j, 0, n - 1)
            {
                if (i != j and a[j] <= a[i] and b[i] <= b[j])
                    break;
            }
            if (j == n)
                res.pb(i + 1);
        }

        j = res.size();

        O << j << '\n';

        F(i, 0, j - 1)
        {
            O << res[i] << ' ';
        }

        O << '\n';
    }
    return 0;
}
