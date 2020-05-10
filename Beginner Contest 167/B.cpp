#include <bits/stdc++.h>
using namespace std;
int main() {
	long a,b,c,k,s=0;
	cin>>a>>b>>c>>k;
	if (a<=k)
	{
		s+=a;
		k-=a;
		if (b<=k)
		{
			k-=b;
			if (c<=k)
				s-=c;
			else
				s-=k;
		}
	}
	else
		s=k;
	cout<<s<<'\n';
	return 0;
}
