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
    ll t,n,q,i,j,k;
    I>>n;
    V<pair<ll, ll>> x(n), neg, pos;
    for (i = 0; i < n; ++i)
    {
        I >> j >> k;
        x[i].first = j;
        x[i].second = k;
        if (x[i].first > 0)
            pos.pb({j, k});
        else
            neg.pb({j, k});
    }
    // sort(all(x));
    sort(all(neg));
    sort(all(pos));
    j = 0;
    for (i = 0; i < n; ++i)
        if (x[i].first < 0)
            ++j;
    k = 0;
    if (j == n / 2 || n - j == n / 2)
        for (i = 0; i < n; ++i)
            k += x[i].second;
    else if (j > n - j)
    {
        for (i = 0; i < pos.size(); ++i)
            k += pos[i].second;
        for (i = j - 1; i >= j - (n - j + 1); --i)
            k += neg[i].second;
    }
    else if (n - j > j)
    {
        for (i = 0; i < j; ++i)
            k += neg[i].second;
        for (i = 0; i <= j; ++i)
            k += pos[i].second;
    }
    O << k << '\n';
    return 0;
}
