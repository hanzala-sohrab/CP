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
ll l2i(char c) {
    switch (c)
    {
        case 'r': return 0;
        case 'm': return 1;
    }
    return -1;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>n;
    string b, g;
    I >> b >> g;
    V<ll> mb(2, 0), mg(2, 0);
    F (i, 0, n - 1)
    {
        ++mb[l2i(b[i])];
        ++mg[l2i(g[i])];
    }
    if (mb[0] == mg[0] && mb[1] == mg[1])
        O << "0";
    else
    {
        F (i, 0, n - 1)
        {
            --mg[l2i(b[i])];
            if (mg[l2i(b[i])] < 0)
                break;
        }
        O << n - i;
    }
    return 0;
}
