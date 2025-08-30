#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
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
        ll n;
        I >> n;

        ll div = 11;
        V<ll> x;

        while (1)
        {
            ll q = n / div;
            if (q == 0)
                break;

            if (n % div == 0 and n % q == 0)
                x.push_back(q);

            div = (div - 1) * 10 + 1;
        }

        const int L = x.size();

        if (L == 0)
        {
            O << "0\n";
            continue;
        }

        O << x.size() << '\n';
        sort(all(x));
        for (ll el : x)
            O << el << ' ';
        O << '\n';
    }
    return 0;
}
