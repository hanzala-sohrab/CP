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
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

bool isPowerOfTwo (ll x) {
    return x && (!(x&(x-1)));
}

// https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
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

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned gcd(unsigned u, unsigned v)
{
    auto shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if(u > v)
            std::swap(u, v);
    } while((v -= u));
    return u << shift;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I>>n;
        V<ll>p(n), a(n+1,0), prefix(n+1,0), b(n+1,0);
        for (i = 0; i < n; i++)
        {
            I>>p[i];
            a[p[i]] = i;
        }
        prefix[1] = p[0];
        F(i,2,n)
        {
            prefix[i] = max(prefix[i-1], p[i-1]);
        }
        j = 1;
        q = n;
        for (i = n; i > 0 and j <= n;)
        {
            k = prefix[i];
            b[j] = k;
            j += q - a[k];
            i = a[k];
            q = i;
        }
        F(i,1,n)
        {
            if (!b[i])
                continue;
            j = a[b[i]] + 2;
            F(k,j,n)
            {
                if (i + 1 <= n)
                {
                    if (b[i + 1])
                        break;
                    b[++i] = p[k - 1];
                }
            }
            // --i;
            // i = k;
            // --i;
        }
        F(i,1,n)
            O<<b[i]<<' ';
        O<<'\n';
    }
    return 0;
}
