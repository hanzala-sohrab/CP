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
    ll t=4*1e5,n,q,i,j,k;
    I>>n>>k>>q;
    V<pair<ll,ll>> range(n);
    F(i,0,n-1)
        I>>range[i].ff>>range[i].ss;
    V<ll> a(t,0);
    F(i,0,n-1)
    {
        // We need [l,r]
        ++a[range[i].ff];   // Add 1 to l th index, i.e., [l, n)
        --a[range[i].ss + 1];   // Subtract r + 1 th index, i.e., [r + 1, n)
    }
    F(i,1,t-1)
        a[i] += a[i - 1];
    F(i,0,t-1)
        a[i] = a[i] >= k ? 1 : 0;
    F(i,1,t-1)
        a[i] += a[i - 1];
    F(i,0,q-1)
    {
        ll b, c;
        I>>b>>c;
        O<<a[c] - a[b-1]<<'\n';
    }
    return 0;
}
