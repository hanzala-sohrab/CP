#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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

        if (n == 0)
        {
            O << "0 0\n";
            continue;
        }

        i = sqrt(n);

        if (i * i != n)
        {
            O << "-1\n";
            continue;
        }

        O << 1 << ' ' << i - 1 << '\n';
    }
    return 0;
}
