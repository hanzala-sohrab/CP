#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, n, s;
        I >> n >> s;
        V<short> a(n);
        int sum = 0;
        F(i, 0, n - 1)
        {
            I >> a[i];
            sum += a[i];
        }

        if (sum > s)
        {
            F(i, 0, n - 1)
            {
                O << a[i] << ' ';
            }
            O << '\n';
            continue;
        }

        if (sum == s or s - sum >= 2)
        {
            O << "-1\n";
            continue;
        }

        int c0 = count(all(a), 0);
        int c1 = count(all(a), 1);
        int c2 = n - c0 - c1;

        F(i, 1, c0)
        {
            O << "0 ";
        }
        F(i, 1, c2)
        {
            O << "2 ";
        }
        F(i, 1, c1)
        {
            O << "1 ";
        }
        O << '\n';
    }
    return 0;
}
