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
    ll t, p, q, r, a, b, c, i, j, k;
    I>>t;
    while (t--)
    {
        I >> p >> q >> r >> a >> b >> c;
        ll x = a - p, y = b - q, z = c - r;
        if (x == y && x == z)
        {
            if (x)
                k = 1;
            else
                k = 0;
        }
        else if (x == y && x != z)
        {
            if (x)
            {
                if (z)
                    k = 2;
                else
                    k = 1;
            }
            else
            {
                if (z)
                    k = 1;
                else
                    k = 0;
            }
        }
        else if (x == z && x != y)
        {
            if (x)
            {
                if (y)
                    k = 2;
                else
                    k = 1;
            }
            else
            {
                if (y)
                    k = 1;
                else
                    k = 0;
            }
        }
        else if (y == z && y != x)
        {
            if (y)
            {
                if (x)
                    k = 2;
                else
                    k = 1;
            }
            else
            {
                if (x)
                    k = 1;
                else
                    k = 0;
            }
        }
        else if (x != y && x != z && y != z)
        {
            if (x && y && z)
                k = 3;
            else if (!x && y && z)
                k = 2;
            else if (x && !y && z)
                k = 2;
            else if (x && y && !z)
                k = 2;
        }   
        O << k << '\n';
    }
    return 0;
}
