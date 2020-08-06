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

ll count_set_bits(ll n) 
{ 
    ll c = 0; 
    while (n)
    {
        n &= (n - 1);
        c++;
    }
    return c;
} 

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k,m;
    // I>>t;
    t=1;
    while (t--)
    {
        I >> n >> m >> k;
        V<ll> x(m+1), b(m+1);
        F(i,0,m)
        {
            I>>x[i];
            // b[i] = count_set_bits(x[i]);
        }
        q = 0;
        F (i,0,m-1)
        {
            j = count_set_bits(x[m] ^ x[i]);
            if (j <= k)
                ++q;
        }
        O << q << '\n';
    }
    return 0;
}
