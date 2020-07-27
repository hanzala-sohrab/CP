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
    ll t, i, j, n, c = 0;
    I>>t;
    while (c++ < t)
    {
        O << "Case #" << c << ":\n";
        string incoming, outgoing;
        I >> n >> incoming >> outgoing;
        V<V<char>> p(n, V<char>(n, 'N'));
        F(i,0,n-1)
        {
            p[i][i] = 'Y';
            for (j = i - 1; j >= 0; --j)
            {
                if (outgoing[i] == 'N')
                    break;
                if (incoming[j] == 'Y' and outgoing[j + 1] == 'Y' and p[i][j + 1] == 'Y')
                    p[i][j] = 'Y';
            }
            for (j = i + 1; j < n; ++j)
            {
                if (outgoing[i] == 'N')
                    break;
                if (incoming[j] == 'Y' and outgoing[j - 1] == 'Y' and p[i][j - 1] == 'Y')
                    p[i][j] = 'Y';
            }
        }       
        F(i,0,n-1)
        {
            F(j,0,n-1)
                O << p[i][j];
            O << '\n';
        }
    }
    return 0;
}