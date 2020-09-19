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
    ll i,k;
    I>>k;
    V<V<ll>> sum(k),a(k);
    V<ll>n(k);
    umap<ll, ll> m;
    bool possible = false;
    F(i,0,k-1)
    {
        ll j,s=0,l;
        I>>n[i];
        sum[i].resize(n[i],0);
        a[i].resize(n[i]);
        F(j,0,n[i]-1)
        {
            I>>a[i][j];
            s+=a[i][j];
        }
        F(j,0,n[i]-1)
        {
            sum[i][j] = s - a[i][j];
            if (found(m,sum[i][j]) and m[sum[i][j]] != i)
            {
                possible = true;
                O<<"YES\n";
                O<<i+1<<' '<<j+1<<'\n';
                O<<m[sum[i][j]]+1<<' ';
                ll s1 = 0, x = m[sum[i][j]];
                F(l,0,n[x])
                    if (sum[x][l] == sum[i][j])
                    {
                        O<<l+1<<'\n';
                        break;
                    }
                break;
            }
            m.insert(mp(sum[i][j], i));
        }
        if (possible)
            break;
    }
    if (!possible)
        O<<"NO\n";
    return 0;
}