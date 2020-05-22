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
    ll W,t,n,q,i,j;
    I>>n>>W;
    vector<ll>w(n),v(n);
    F(i,0,n-1)
        I>>w[i]>>v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));
    for (i=1;i<=n;++i)
    {
        for (j=0;j<=W;++j)
        {
            if (j>=w[i-1])
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W]<<'\n';
    return 0;
}