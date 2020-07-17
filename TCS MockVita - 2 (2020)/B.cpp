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

ll bit_score(ll a) {
    ll x = a % 10, y = (a / 10) % 10, z = a / 100;
    return (mmax(x, y, z) * 11 + mmin(x, y, z) * 7) % 100;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k = 0;
    I >> n;
    V<ll> a(n), b(n);
    umap<ll, V<ll>> m;
    F (i, 0, n - 1)
    {
        I >> a[i];
        b[i] = bit_score(a[i]);
        j = b[i] / 10;
        if (m.find(j) == m.end())
        {
            V<ll> x;
            x.pb(i + 1);
            m.insert(pair<ll, V<ll>>(j, x));
        }
        else
            m[j].pb(i + 1);
    }
    for (auto it: m)
    {
        j = it.first;
        V<ll> x = it.second;
        ll e = 0, o = 0;
        F (i, 0, (ll)x.size() - 1)
        {
            if (x[i] & 1)
                ++o;
            else
                ++e;
        }
        if (e >= 3 or o >= 3)
            k += 2;
        else
            k += (e / 2) + (o / 2);

    }
    O << k;
    return 0;
}
