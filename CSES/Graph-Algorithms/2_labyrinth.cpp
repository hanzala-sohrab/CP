#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
	ll n, m, i, j;
	I >> n >> m;
	V<V<char>> labyrinth(n, V<char>(m));
	F(i,0,n-1)
		F(j,0,m-1)
			I >> labyrinth[i][j];
	
    return 0;
}
