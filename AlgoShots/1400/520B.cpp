#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,m,q,i,j,k;
    I>>n>>m;
    if (m <= n)
        q = n - m;
    else
    {
        V<ll> dp(m+1);
        F(i,1,n)
            dp[i] = n - i;
        F(i,n+1,m)
            dp[i] = i & 1 ? dp[(i + 1) / 2] + 2 : dp[i / 2] + 1;
        q = dp[m];
    }
    O<<q<<'\n';
    return 0;
}