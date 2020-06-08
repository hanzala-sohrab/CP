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
        V<ll> a(n);
        ll c5 = 0, c10 = 0, c15 = 0;
        F (i, 0, n - 1)
            I >> a[i];
        if (a[0] != 5)
            O << "NO\n";
        else
        {
            F (i, 0, n - 1)
            {
                if (a[i] == 5)
                    ++c5;
                else if (a[i] == 10)
                {
                    ++c10;
                    if (c5 > 0)
                        --c5;
                    else
                    {
                        c5 = -1;
                        break;
                    }
                }
                else if (a[i] == 15)
                {
                    ++c15;
                    if (c10 > 0)
                        --c10;
                    else if (c5 > 1)
                        c5 -= 2;
                    else
                    {
                        c5 = -1;
                        break;
                    }
                }
            }
            if (c5 >= 0 && c10 >= 0 && c15 >= 0)
                O << "YES\n";
            else
                O << "NO\n";
        }
    }
    return 0;
}
