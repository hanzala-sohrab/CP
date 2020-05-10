#include <bits/stdc++.h>
using namespace std;
int main() {
	string s,t;
	cin>>s>>t;
	int ls=s.size(),lt=t.size();
	bool val=true;
	for (int i=0;i<ls;++i)
	{
		char c=s[i];
		if (c!=t[i])
		{
			val=false;
			break;
		}
	}
	if (val)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}
