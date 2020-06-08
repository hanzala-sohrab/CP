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
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j;
    I>>n;
    V<ll> h(n),dp(n+1,0);
    F(i,0,n-1)
        I>>h[i];
    dp[2]=abs(h[1]-h[0]);
    if (n>2)
    {
        dp[3]=min(dp[2]+abs(h[2]-h[1]),abs(h[2]-h[0]));
        for (i=4;i<=n;++i)
            dp[i]=min(dp[i-1]+abs(h[i-1]-h[i-2]),dp[i-2]+abs(h[i-1]-h[i-3]));
    }
    cout<<dp[n]<<'\n';
    return 0;
}