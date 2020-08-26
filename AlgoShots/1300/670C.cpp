#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, m, i, ans = 0;
    I>>n;
    umap<ll, ll> a;
    F(i,0,n-1)
    {
        I>>ans;
        if (found(a, ans))
            ++a[ans];
        else
            a.insert(mp(ans, 1));
    }
    I>>m;
    V<ll>b(m),c(m);
    F(i,0,m-1)
        I>>b[i];
    F(i,0,m-1)
        I>>c[i];
    ll t = 0, t1 = 0;
    for (i = ans = 0; i < m; ++i)
    {
        if (t < a[b[i]])
        {
            ans = i;
            t = a[b[i]];
            t1 = a[c[i]];
        }
        if (t == a[b[i]])
        {
            if (t1 < a[c[i]])
            {
                ans = i;
                t1 = a[c[i]];
            }
        }
    }
    O<<ans + 1<<'\n';
    return 0;
}