#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        if (n % 2 == 0)
            O << n / 2 << ' ' << n / 2 << '\n';
        else
        {
            ll x = n;
            for (i = 3; i * i <= n; i += 2)
                if (n % i == 0)
                {
                    x = i;
                    break;
                }
            O << n / x << ' ' << n - n / x << '\n';
        }
    }
    return 0;
}
