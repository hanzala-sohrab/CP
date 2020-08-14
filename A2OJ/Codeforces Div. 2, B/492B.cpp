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
    ll n, l, i;
    double d = 0;
    I >> n >> l;
    V<ll> a(n);
    F(i,0,n-1)
        I >> a[i];
    sort(all(a));
    F(i,0,n-2)
        d = d > a[i + 1] - a[i] ? d : a[i + 1] - a[i];
    d /= 2;
    d = d > l - a[n - 1] ? d : l - a[n - 1];
    d = d > a[0] ? d : a[0];
    printf("%.10f\n", d);
    return 0;
}