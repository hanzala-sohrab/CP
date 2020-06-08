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
const ll L=1e5+1;
V<bool> visited;
V<V<ll>>adj;
V<ll> in_degree, dist;
void dfs(ll a) {
    visited[a]=true;
    for (ll b: adj[a])
    {
        dist[b]=max(dist[b], dist[a]+1);
        --in_degree[b];
        if (!in_degree[b])
            dfs(b);
    }
}
int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n,m,q,i,j,k=0;
    I>>n>>m;
    visited.resize(n,false);
    adj.resize(n);
    in_degree.resize(n);
    dist.resize(n);
    F (q,0,m-1)
    {
        I>>i>>j;
        adj[i-1].pb(j-1);
        in_degree[j-1]++;
    }
    F (i,0,n-1)
        if (!visited[i] && !in_degree[i])
            dfs(i);
    F (i,0,n-1)
        k=max(k,dist[i]);
    O<<k<<'\n';
    return 0;
}