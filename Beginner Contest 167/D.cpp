#include<bits/stdc++.h>
using namespace std;
int main() {
	long n,k,i,j,ans=0;
	cin>>n>>k;
	vector<long> a(n), path;
	vector<bool>visited(n,false);
	for (i=0;i<n;++i)
		cin>>a[i];
	path.push_back(0);
	visited[0]=true;
	for (i=1;i<=k;++i)
	{
		ans=a[ans]-1;
		if (visited[ans])
			break;
		path.push_back(ans);
		//cout<<ans<<' ';
		visited[ans]=true;
	}
	int l=path.size();
	for (j=0;j<l;++j)
		if (path[j]==ans)
			break;
	int l1=l-j;
	k-=i;
	//cout<<'\n'<<k<<'\n';
	k%=l1;
	ans=path[j+k]+1;
	cout<<ans;
	return 0;
}
