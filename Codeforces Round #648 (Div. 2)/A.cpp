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

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, m, i, j, k;
    I>>t;
    while (t--)
    {
        I >> n >> m;
        ll a[n][m];
        V<bool> rows(n, false), cols(m, false);
        F (i, 0, n - 1)
            F (j, 0, m - 1)
            {
                I >> a[i][j];
                if (a[i][j])
                    rows[i] = cols[j] = true;
            }
        ll c = 1;
        F (i, 0, n - 1)
        {
            if (!rows[i])
            {
                F (j, 0, m - 1)
                {
                    if (!cols[j])
                    {
                        a[i][j] = 1;
                        rows[i] = cols[j] = true;
                        ++c;
                        break;
                    }
                }
            }
        }
        if (c & 1)
            O << "Vivek\n";
        else
            O << "Ashish\n";
    }
    return 0;
}
