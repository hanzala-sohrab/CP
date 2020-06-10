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
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I >> n;
        ll o = 0, z = 0;
        V<ll> a(n), b(n);
        F (i, 0, n - 1)
            I >> a[i];
        F (i, 0, n - 1)
        {
            I >> b[i];
            if (b[i])
                ++o;
            else
                ++z;
        }
        if (z && o)
            O << "Yes\n";
        else
        {
            if (!z)
            {
                F (i, 1, n - 1)
                    if (a[i] < a[i - 1])
                        break;
                if (i == n)
                    O << "Yes\n";
                else
                    O << "No\n";
            }
            else
            {
                F (i, 1, n - 1)
                    if (a[i] < a[i - 1])
                        break;
                if (i == n)
                    O << "Yes\n";
                else
                    O << "No\n";
            }
        }
    }
    return 0;
}
