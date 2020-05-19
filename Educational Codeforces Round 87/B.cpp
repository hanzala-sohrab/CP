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
	string s;
	I>>s;
	bool v[5]={false};
	ll l=s.size();
	if (l<3)
	{
		cout<<"0\n";
		continue;
	}
	F(i,0,l-1)
		v[s[i]-48]=true;
	if (!v[1]||!v[2]||!v[3])
		cout<<"0\n";
	else
	{
		ll c=1;
		v[1]=v[2]=v[3]=false;
		F(i,0,l-2)
			if (s[i]!=s[i+1])
				break;
		s=s.substr(i);
		//cout<<s<<'\n';
		l=s.size();
		F(i,0,l-1)
		{
			if (s[i]=='1')
			{
				if (i+1<l&&s[i+1]=='2')
				{
					if (v[2])
					{
						c=2;
						v[3]=false;
					}
					else
					{
						v[2]=true;
						++c;
					}
				}
				else if (i+1<l&&s[i+1]=='3')
				{
					if (v[3])
					{
						c=2;
						v[2]=false;
					}
					else
					{
						v[3]=true;
						++c;
					}
				}
				else if (i+1<l&&s[i+1]=='1')
					++c;
				v[1]=true;
			}
			else if (s[i]=='2')
			{
				if (i+1<l&&s[i+1]=='1')
				{
					if (v[1])
					{
						c=2;
						v[3]=false;
					}
					else
					{
						v[1]=true;
						++c;
					}
				}
				else if (i+1<l&&s[i+1]=='3')
				{
					if (v[3])
					{
						c=2;
						v[1]=false;
					}
					else
					{
						v[3]=true;
						++c;
					}
				}
				else if (i+1<l&&s[i+1]=='2')
					++c;
				v[2]=true;
			}
			else if (s[i]=='3')
			{
				if (i+1<l&&s[i+1]=='1')
				{
					if (v[1])
					{
						c=2;
						v[2]=false;
					}
					else
					{
						v[1]=true;
						++c;
					}
				}
				else if (i+1<l&&s[i+1]=='2')
				{
					if (v[2])
					{
						c=2;
						v[1]=false;
					}
					else
					{
						v[2]=true;
						++c;
					}
				}
				else if (i+1<l&&s[i+1]=='3')
					++c;
				v[3]=true;
			}
			if (v[1]&&v[2]&&v[3])
			{
				cout<<c<<'\n';
				break;
			}
		}
	}
    }
    return 0;
}
