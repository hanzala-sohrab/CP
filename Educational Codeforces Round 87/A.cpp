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

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j;
    I>>t;
    while (t--)
    {
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a<=b)
		cout<<b<<'\n';
	else if (c<=d)
		cout<<"-1\n";
	else
	{
		n=(ll)ceil((a-b)/(c-d+0.0));
		cout<<b+n*c<<'\n';
	}
    }
    return 0;
}
