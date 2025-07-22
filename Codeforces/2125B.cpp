#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        ll a, b, k;
        I >> a >> b >> k;

        if (a == 0 or b == 0)
        {
            O << "0\n";
            continue;
        }
        if (a == b or k >= max(a, b))
        {
            O << "1\n";
            continue;
        }

        ll g = gcd(a, b);
        if (g > 1 and max(a, b) / g <= k)
        {
            O << "1\n";
            continue;
        }

        O << "2\n";
    }
    return 0;
}
