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
    ll t, i, j, k, x, y, z, a, b, c;
    I>>t;
    while (t--)
    {
        I >> x >> y >> z;
        if (x == y and y == z)
            O << "YES\n" << x << ' ' << x << ' ' << x << '\n';
        else
        {
            if (x != y and y != z and x != z)
                O << "NO\n";
            else
            {
                i = max(x, max(y, z));
                // O << i << '\n';
                bool t = true;
                if (x == y)
                {
                    if (i == x)
                    {
                        a = x;
                        b = 1;
                        c = z;
                    }
                    else
                    {
                        O << "NO\n";
                        t = false;
                    }
                }
                else if (x == z)
                {
                    if (i == x)
                    {
                        a = y;
                        b = x;
                        c = 1;
                    }
                    else
                    {
                        O << "NO\n";
                        t = false;
                    }
                }
                else if (y == z)
                {
                    if (i == y)
                    {
                        a = 1;
                        b = x;
                        c = y;
                    }
                    else
                    {
                        O << "NO\n";
                        t = false;
                    }
                }
                if (t)
                {
                    O << "YES\n";
                    O << a << ' ' << b << ' ' << c << '\n';
                }
            }  
        }
    }
    return 0;
}
