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
    ll t, n, i, a, b ,c = 0;
    I>>t;
    while (c++ < t)
    {
        O << "Case #" << c << ":\n";
        string C;
        I >> n >> C;
        a = b = 0;
        for (char ch:C)
            ch == 'A' ? ++a : ++b;
        if (abs(a - b) == 1)
            O << "Y\n";
        else
            O << "N\n";
    }
    return 0;
}