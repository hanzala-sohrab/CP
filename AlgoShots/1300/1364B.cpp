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
    I>>t;
    while (t--)
    {
        I>>n;
        V<ll>p(n),a;
        F(i,0,n-1)
            I>>p[i];
        a.pb(p[0]);
        F(i,1,n-2)
        {
            if (p[i - 1] > p[i] and p[i] < p[i + 1])
                a.pb(p[i]);
            else if (p[i - 1] < p[i] and p[i] > p[i + 1])
                a.pb(p[i]);
        }
        a.pb(p[n - 1]);
        O << a.size() << '\n';
        F(i,0,a.size() - 1)
            O << a[i] << ' ';
        O << '\n';
    }
    return 0;
}