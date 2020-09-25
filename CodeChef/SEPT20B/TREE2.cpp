#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

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
