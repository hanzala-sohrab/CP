#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, m = LONG_LONG_MAX, r, mi = -1, j;
    I>>n;
    V<ll> a(n);
    F(i,0,n-1)
        I>>a[i];
    F(i,0,n-1)
    {
        r = a[i] - i;
        j = 0;
        if (r > 0)
        {
            if (r % n == 0)
                j = (r / n) * n + i;
            else
                j = (r / n + 1) * n + i;
        }
        if (m > j)
        {
            m = j;
            mi = i;
        }
    }
    O<<mi + 1<<'\n';
    return 0;
}
