#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t;
    I >> t;
    while (t--)
    {
        ll n, i, k;
        I >> n >> k;
        V<ll> a(n), b(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }
        F(i, 0, n - 1)
        {
            I >> b[i];
        }

        ll requiredSum = -1;

        F(i, 0, n - 1)
        {
            if (b[i] != -1)
            {
                requiredSum = a[i] + b[i];
                break;
            }
        }

        bool isAnswerPossible = true;

        if (requiredSum != -1)
        {
            F(i, 0, n - 1)
            {
                if (b[i] == -1)
                {
                    if (a[i] > requiredSum)
                    {
                        isAnswerPossible = false;
                        break;
                    }

                    b[i] = requiredSum - a[i];
                }

                if (a[i] + b[i] != requiredSum or b[i] > k)
                {
                    isAnswerPossible = false;
                    break;
                }
            }
        }

        if (!isAnswerPossible)
        {
            O << "0\n";
            continue;
        }

        ll M = *max_element(all(a));
        ll m = *min_element(all(a));

        O << (requiredSum >= 0 ? 1 : k - (M - m) + 1) << '\n';
    }
    return 0;
}
