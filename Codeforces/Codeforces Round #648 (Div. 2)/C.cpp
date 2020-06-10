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

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    t = 1;
    while (t--)
    {
        I >> n;
        V<ll> a(n), b(n), p(n + 1);
        unordered_map<ll, ll> f;
        F (i, 0, n - 1)
        {
            I >> a[i];
            p[a[i]] = i;
        }
        F (i, 0, n - 1)
            I >> b[i];
        ll m = 0, c;
        F (i, 0, n - 1)
        {
            c = i - p[b[i]];
            c = c < 0 ? c + n : c;
            f[c]++;
        }
        for (auto it: f)
            m = max(m, it.ss);
        O << m << '\n';
    }
    return 0;
}