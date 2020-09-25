#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

// bool isPowerOfTwo (ll x) {
//     return x && (!(x&(x-1)));
// }

// // https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
// ll binpow(ll a, ll b) {
//     a %= M;
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % M;
//         a = a * a % M;
//         b >>= 1;
//     }
//     return res;
// }

// // https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
// unsigned gcd(unsigned u, unsigned v)
// {
//     auto shift = __builtin_ctz(u | v);
//     u >>= __builtin_ctz(u);
//     do
//     {
//         v >>= __builtin_ctz(v);
//         if(u > v)
//             std::swap(u, v);
//     } while((v -= u));
//     return u << shift;
// }

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I>>n;
        umap<ll,ll> m;
        F(i,0,n-1)
        {
            I>>j;
            if (j and found(m, j))
                ++m[j];
            else if (j)
                m.insert(mp(j,1));
        }
        O<<m.size()<<'\n';
    }
    return 0;
}
