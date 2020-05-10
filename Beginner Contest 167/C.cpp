#include<bits/stdc++.h>
struct B
{
	long c;
	long *a;
};
bool C(struct X,struct Y) {
	return X.c<Y.c;
}
using namespace std;
int main() {
	int n,m,x,cost=0;
	cin>>n>>m>>x;
	vector<long>understanding(m,0);
	vector<B> b(n);
	for (int i=0;i<n;++i)
	{
		cin>>b[i].c;
		for (int j=0;j<m;++j)
			cin>>b[i][j].a;
	}
	sort(b.begin(),b.end(),C);
	for (int i=0;i<n;++i)
	{

	return 0;
}
