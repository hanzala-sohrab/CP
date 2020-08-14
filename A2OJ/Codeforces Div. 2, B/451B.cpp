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
    ll n, seg = 0, i, j, k, l = 0, r = 0, minimas = 0;
    I >> n;
    V<ll> a(n), b(n);
    bool possible = true, sorted = true;
    // umap<ll, ll> m;
    F(i,0,n-1)
    {
        I>>a[i];
        // b[i] = a[i];
        // m.insert(pair<ll, ll>(a[i], i));
    }
    F(i,1,n-1)
        if (a[i] < a[i - 1])
            sorted = false;
    if (sorted)
        O << "yes\n1 1\n";
    else
    {
        F(i,0,n-2)
        if (a[i + 1] < a[i])
            break;
        l = i + 1;
        for (i = n - 1; i > 0; --i)
            if (a[i] < a[i - 1])
                break;
        r = i + 1;
        // O << l << ' ' << r << '\n';
        for (i = 0; i < l - 1; ++i)
            b[i] = a[i];
        j = i;
        for (i = r - 1; i >= l - 1; --i)
            b[j++] = a[i];
        for (i = r; i < n; ++i)
            b[i] = a[i];
        for (i = 0; i < n - 1; ++i)
            // O << b[i] << ' ';
            if (b[i] > b[i + 1])
            {
                possible = false;
                break;
            }
        if (possible)
            O << "yes\n" << l << ' ' << r << '\n';
        else
            O << "no\n";
    }
    return 0;
}
