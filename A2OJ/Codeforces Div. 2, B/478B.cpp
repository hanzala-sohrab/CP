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

ll nC2(ll n) {
    return (n * (n - 1)) / 2;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, m, i, mi = 0, ma, j, k;
    I >> n >> m;
    if (n == 1 or n == m)
        O << "0 0\n";
    else if (n == 2 or n == 3 or n - m == 1)
        O << "1 1\n";
    else
    {
        if (m == 1)
        {
            ma = nC2(n);
            O << ma << ' ' << ma << '\n';
        }
        else
        {
            ma = nC2(n - (m - 1));
            j = n / m;
            k = n % m;
            for (i = 1; i <= k; ++i)
                mi += nC2(j + 1);
            for (; i <= m; ++i)
                mi += nC2(j);
            O << mi << ' ' << ma << '\n';
        }
    }
    
    return 0;
}
