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
    int t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I >> n;
        V<int> p(2 * n), c(n, 0);
        j = 2 * n - 1;
        F (i, 0, j)
            I >> p[i];
        F (i, 0, j)
            if (!c[p[i] - 1])
            {
                O << p[i] << ' ';
                // m.insert(pair<ll, ll>(p[i], 1));
                ++c[p[i] - 1];
            }
        O << '\n';
    }
    return 0;
}
