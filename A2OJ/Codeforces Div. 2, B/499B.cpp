#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define M 1000000007
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define umap unordered_map

bool isPowerOfTwo (ll x) {
    return x && (!(x&(x-1)));
}

ll binpow(ll a, ll b) {
    a %= M;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, m, i;
    I >> n >> m;
    V<string> a(m), b(m), c(n);
    umap<string, V<string>> d;
    F(i,0,m-1)
    {
        I>>a[i]>>b[i];
        V<string> x = {a[i], b[i]};
        d.insert(make_pair(a[i], x));
    }
    F(i,0,n-1)
        I>>c[i];
    F(i,0,n-1)
    {
        if (d[c[i]][0].size() <= d[c[i]][1].size())
            O << d[c[i]][0] << ' ';
        else
            O << d[c[i]][1] << ' ';
    }
    O << '\n';
    return 0;
}