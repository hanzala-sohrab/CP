#include <bits/stdc++.h>
using namespace std;
#define ll long long
void bfs(ll source,ll s,vector<vector<ll>>&adj,vector<bool>&visited) {
	if (s==0)
	{
		visited[source]=true;
		return;
	}
	ll n=adj.size();
	queue<ll> q;
	q.push(source);
	vector<ll>d(n,0);
	visited[source]=true;
	while (!q.empty())
	{
		ll v=q.front();
		q.pop();
		if (d[v]==s)
			return;
		for (ll i=0;i<adj[v].size();++i)
		{
			ll u=adj[v][i];
			if (!visited[u])
			{
				visited[u]=true;
				q.push(u);
				d[u]=d[v]+1;
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	while (t--)
	{
		ll n,r,m;
		cin>>n>>r>>m;
		vector<vector<ll>> adj(n);
		vector<bool> visited(n,false);
		for (ll i=0;i<r;++i)
		{
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool val=true;
		for (ll i=0;i<m;++i)
		{
			ll k,s;
			cin>>k>>s;
			--k;
			if (val)
				if (!visited[k])
					bfs(k,s,adj,visited);
				else
					val=false;
		}
		for (ll i=0;i<n;++i)
		{
			if (!visited[i])
			{
				val=false;
				break;
			}
		}
		if (val)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
