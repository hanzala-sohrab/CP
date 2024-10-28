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
    ll t, n, i;
    I >> t;
    while (t--)
    {
        I >> n;
        if (n == 1)
        {
            O << "0\n";
            continue;
        }
        F(i, 1, n - 1)
        {
            O << 0;
        }
        O << "1\n";
    }
    return 0;
}
