#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define ff first
#define ss second

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, x, y, ans = 0;
    I>>n;
    map<ll, ll> m1, m2;
    F(i,0,n-1)
    {
        I>>x>>y;
        ++m1[(x - y)];
        ++m2[x + y];
    }
    for (auto it: m1)
        ans += it.ss * (it.ss - 1) / 2;
    for (auto it: m2)
        ans += it.ss * (it.ss - 1) / 2;
    O << ans << '\n';
    return 0;
}