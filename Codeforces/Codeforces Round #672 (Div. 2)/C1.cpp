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
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

bool isPowerOfTwo (ll x) {
    return x && (!(x&(x-1)));
}

// https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
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

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned gcd(unsigned u, unsigned v)
{
    auto shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if(u > v)
            std::swap(u, v);
    } while((v -= u));
    return u << shift;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I>>n>>q;
        V<ll>a(n),b;
        F(i,0,n-1)
            I>>a[i];
        if (n > 1)
            if (a[0] > a[1])
                b.pb(0);
        F(i,1,n-2)
        {
            if (a[i - 1] < a[i] and a[i] >= a[i + 1])
                b.pb(i);
            else if (a[i - 1] >= a[i] and a[i] < a[i + 1])
                b.pb(i);
        }
        if (n > 1)
            if (a[n - 1] >= a[n - 2])
                b.pb(n - 1);
        k = 0;
        j = b.size();
        F(i,0,j-1)
        {
            if (i & 1)
                k -= a[b[i]];
            else
                k += a[b[i]];
            // O<<a[b[i]]<<' ';
        }
        // O<<'\n';
        if (n == 1)
            k = a[0];
        O<<k<<'\n';

    }
    return 0;
}
