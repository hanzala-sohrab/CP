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
    int t;
    I >> t;
    while (t--)
    {
        int i, j = 0, k, n;
        ll p1, p2, q1, q2;
        double S = 0.0;
        I >> n >> p1 >> p2 >> q1 >> q2;
        F(i, 0, n - 1)
        {
            I >> k;
            S += k;
            j = max(j, k);
        }

        double d = sqrt((q1 - p1) * (q1 - p1) + (q2 - p2) * (q2 - p2));
        S += d;
        double m = d <= j ? j : d;

        O << (m <= S - m ? "yes" : "no") << '\n';
    }
    return 0;
}
