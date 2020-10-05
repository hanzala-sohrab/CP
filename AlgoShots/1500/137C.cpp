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
    ll t=0,n,q,i,j,k;
    I>>n;
    V<pair<ll, ll>> d(n);
    F(i,0,n-1)
        I>>d[i].ff>>d[i].ss;
    sort(all(d));
    q = d[0].ss;
    F(i,1,n-1)
        if (q > d[i].ss)
            ++t;
        else
            q = d[i].ss;
    O<<t<<'\n';
    return 0;
}