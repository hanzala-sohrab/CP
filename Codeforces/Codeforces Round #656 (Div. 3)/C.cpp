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

bool is_good(ll v[],  ll n) {
    ll i, j, k, l = n;
    V<ll> x(n);
    for (i = k = 0, j = l - 1; i <= j; ++k)
    {
        if (v[i] <= v[j])
        {
            x[k] = v[i];
            ++i;
        }
        else
        {
            x[k] = v[j];
            --j;
        }
        if (k > 0 and x[k] < x[k - 1])
            return false;
    }
    return x.size() == l;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I >> n;
        k = 0;
        ll a[n];
        bool v = true;
        F (i, 0, n - 1)
            I >> a[i];
        j = n;
        F (i, 0, n - 1)
        {
            bool val = is_good(a + i, j);
            if (val)
            {
                k = i;
                break;
            }
            --j;
        }
        O << k << '\n';
    }
    return 0;
}
