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
        I >> n;
        ll m[n][n];
        k = 0;
        if (n & 1)
            F (i, 0, n - 1)
                F (j, 0, n - 1)
                    m[i][j] = ++k;
        else
            F (i, 0, n - 1)
            {
                if (i & 1)
                {
                    F (j, 1, n - 1)
                        m[i][j] = ++k;
                    m[i][0] = ++k;
                }
                else
                    F (j, 0, n - 1)
                        m[i][j] = ++k;
            }
        F (i, 0, n - 1)
        {
            F (j, 0, n - 1)
                O << m[i][j] << ' ';
            O << '\n';
        }
    }
    return 0;
}
