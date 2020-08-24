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
    ll t,n,i,a,b,x,m,l,r,c;
    I>>t;
    while (t--)
    {
        I>>n>>x>>m;
        c=1;
        a = b = x;
        F(i,1,m)
        {
            I>>l>>r;
            if (l <= a and b <= r)
            {
                c+=r-l - (b - a);
                a = l;
                b = r;
            }
            else if (a < l and r < b)
                continue;
            else if (a < l and b < r and b > l)
            {
                c += r - b;
                b = r;
            }
            else if (a > l and b > r and a < r)
            {
                c += a - l;
                a = l;
            }
            else if (r == a)
            {
                c += r - l;
                a = l;
            }
            else if (l == b)
            {
                c += r - l;
                b = r;
            }
        }
        O << c << '\n';
    }
    return 0;
}
