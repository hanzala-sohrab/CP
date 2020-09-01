#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 100003
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, m, i, j;
    I>>n>>m;
    V<V<ll>> mat(n, V<ll>(m)), f(n, V<ll>(m));

    // generating primes less than 1e5+4
    map<ll, bool> is_prime;
    V<ll> primes;
    V<bool> p(M, true);
    for (i=2;i*i<=M;++i)
        if (p[i])
            for (j=i*i;j<=M;j+=i)
                p[j] = false;
    F(i,2,M)
        if (p[i])
        {
            primes.pb(i);
            is_prime[p[i]] = true;
        }
    auto it = primes.begin();

    // Matrix input
    F(i,0,n-1)
        F(j,0,m-1)
        {
            I>>mat[i][j];
            if (mat[i][j] != 1 and p[mat[i][j]])
                f[i][j] = 0;
            else
            {
                ll pos = lower_bound(all(primes), mat[i][j]) - it;
                if (pos == 0 or pos == primes.size())
                    f[i][j] = abs(mat[i][j] - primes[pos]);
                else
                    f[i][j] = abs(mat[i][j] - primes[pos]);
            }
        }

    ll mi = INT_MAX, r, c;
    F(i,0,n-1)
    {
        r = 0;
        F(j,0,m-1)
            r += f[i][j];
        mi = min(mi, r);
    }
    F(i,0,m-1)
    {
        c = 0;
        F(j,0,n-1)
            c += f[j][i];
        mi = min(mi, c);
    }
    O<<mi<<'\n';
    return 0;
}