#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>n;
    V<pair<ll,ll>> a(n);
    F(i,0,n-1)
    {
        I>>a[i].ff;
        a[i].ss = i;
    }
    sort(all(a));

    q = a[0].ss;
    V<ll> b(n,-1);
    b[a[0].ss] = -1;

    F(i,1,n-1)
        if (a[i].ss <= q)
            b[a[i].ss] = q - a[i].ss - 1;
        else
        {
            q = a[i].ss;
            b[q] = -1;
        }

    F(i,0,n-1)
        O<<b[i]<<' ';
    O<<'\n';
    return 0;
}
