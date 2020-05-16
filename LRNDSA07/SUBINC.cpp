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
    cin>>t;
    vector<ll> T(1e5+1,0);
    T[0]=0;
    T[1]=1;
    T[2]=3;
    T[3]=6;
    T[4]=10;
    for (i=5;i<=1e5;++i)
    {
	    T[i]=2*T[i-1]-T[i-2]+1;
    }
    while (t--)
    {
	cin>>n;
	vector<int>a(n);
	for (i=0;i<n;++i)
	    cin>>a[i];
	ll c=1,o=0;
	for (i=0;i<n;++i)
	{
		if (i<n-1 && a[i+1]>=a[i])
			++c;
		else
		{
			o+=T[c];
			c=1;
		}
	}
	if (n==1)
		o=1;
	cout<<o<<'\n';
    }
    return 0;
}
