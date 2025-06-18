#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 6; i * i <= n; i += 6)
        if (n % (i - 1) == 0 || n % (i + 1) == 0)
            return false;
    return true;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, x, y, k;
    I >> t;
    while (t--)
    {
        I >> x >> k;

        if (k > 1 and x > 1)
        {
            O << "NO\n";
            continue;
        }

        y = x;

        if (x == 1)
        {
            if (k == 1)
            {
                O << "NO\n";
                continue;
            }
            ll i;
            for (i = 1; i < k; ++i)
            {
                y = y * 10 + 1;
            }
        }

        O << (isPrime(y) ? "YES" : "NO") << '\n';
    }
    return 0;
}
