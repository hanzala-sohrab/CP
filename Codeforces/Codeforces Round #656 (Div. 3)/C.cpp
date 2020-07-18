#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, i, j;
    I >> t;
    while (t--)
    {
        I >> n;
        ll a[n];
        F (i, 0, n - 1)
            I >> a[i];
        // Answer is the index at which the first minima from the right end is found.
        for (i = n - 1; i >= 0; )
        {
            while (i > 0 and a[i - 1] >= a[i])
                --i;
            while (i > 0 and a[i - 1] <= a[i])
                --i;
            break;
        }
        O << i << '\n';
    }
    return 0;
}