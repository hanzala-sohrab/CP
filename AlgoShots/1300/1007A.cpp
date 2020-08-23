#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, j, c = 0;
    I>>n;
    V<ll> a(n);
    F(i,0,n-1)
        I>>a[i];
    sort(all(a));
    for (i = j = 0; j < n and i < n; )
    {
        while (j < n and i < n and a[i] == a[j])
            ++j;
        while (j < n and i < n and a[j] > a[i])
        {
            ++i;
            ++j;
            ++c;
        }
    }
    O << c << '\n';
    return 0;
}