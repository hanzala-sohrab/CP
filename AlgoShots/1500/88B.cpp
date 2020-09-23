#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x)!=m.end())

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n,m,x,i,j,ans = 0,i1,l,s=0;
    string t;
    I>>n>>m>>x;
    V<V<char>> k(n, V<char>(m));
    V<pair<ll,ll>> pairs;
    umap<char, bool> keys;
    F(i,0,n-1)
        F(j,0,m-1)
        {
            I>>k[i][j];
            if (!found(keys, k[i][j]))
                keys.insert(mp(k[i][j], true));
            if (k[i][j] == 'S')
            {
                ++s;
                pairs.pb(mp(i,j));
            }
        }
    I>>l>>t;

    V<double> ch(26,INT_MAX);

    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            double d = 0, md = INT_MAX;
            F(i1,0,s-1)
            {
                d = (pairs[i1].ff - i) * (pairs[i1].ff - i) + (pairs[i1].ss - j) * (pairs[i1].ss - j);
                md = min(md, d);
            }
            ch[k[i][j] - 'a'] = min(sqrt(md), ch[k[i][j] - 'a']);
        }
    }
    bool possible = true;
    F(i,0,l-1)
    {
        char c = t[i];
        if (isupper(t[i]))
            c = t[i] + 32;
        if ((isupper(t[i]) and !s) or !found(keys, c))
        {
            possible = false;
            break;
        }
        if (isupper(t[i]) and ch[c - 'a'] > x)
            ++ans;
    }
    if (!possible)
        O<<"-1\n";
    else
        O<<ans<<'\n';
    return 0;
}
