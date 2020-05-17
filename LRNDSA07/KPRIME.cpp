#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define M 1000000007



int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    ll t,n,q,i,j;
    vector<ll> marked(1e5+1,0);
    vector<vector<ll>>T(1e5+1,vector<ll>(6,0));
    for (i=2;i<=1e5;++i)
	    if (!marked[i])
		    for (j=i;j<=1e5;j+=i)
			    marked[j]++;
    for (i=2;i<=1e5;++i)
    {
	    for (j=1;j<=5;++j)
		    T[i][j]=T[i-1][j];
	    ll v=marked[i];
	    if (1<=v<=5)
		    T[i][v]++;
    }
    cin>>t;
    while (t--)
    {
	ll a,b,k,c=0;
	cin>>a>>b>>k;
	c=T[b][k]-T[a-1][k];
	cout<<c<<'\n';
    }
    return 0;
}
