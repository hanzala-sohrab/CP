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

ll sod(ll x) {
    ll s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I >> n;
        ll x, s, sq;
        for (s = 0; s < 91; ++s)
        {
            k = 4 * n + s * s;
            sq = sqrt(k);
            if (k == sq * sq)
                break;
        }
        x = (sq - s) / 2;
        if (sod(x) != s)
            x = -1;
        O << x << '\n';
    }
    return 0;
}
