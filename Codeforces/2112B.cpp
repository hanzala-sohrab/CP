#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

bool checkBeauty(V<ll> &a)
{
    const int N = a.size();

    for (int i = 0; i < N - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            return true;
        }
    }

    return false;
}

bool checkSorted(V<ll> &a)
{
    ll i, n = a.size();

    bool isSorted = true;

    F(i, 0, n - 2)
    {
        if (a[i + 1] < a[i])
        {
            isSorted = false;
            break;
        }
    }

    if (isSorted)
    {
        return true;
    }

    isSorted = true;

    F(i, 0, n - 2)
    {
        if (a[i + 1] > a[i])
        {
            isSorted = false;
            break;
        }
    }

    return isSorted;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        V<ll> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }

        bool isBeautiful = checkBeauty(a);

        if (isBeautiful)
        {
            O << "0\n";
            continue;
        }

        O << (checkSorted(a) ? -1 : 1) << '\n';
    }
    return 0;
}
