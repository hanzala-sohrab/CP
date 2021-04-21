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
    ll n, x, i, j;
    I >> n >> x;
    V<ll> c(n), dp(x + 1, INT_MAX);
    F(i,0,n-1)
        I>>c[i];
    dp[0] = 0;
    F(i,1,x)
        F(j,0,n-1)
            if (i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
    if (dp[x] == INT_MAX)
        dp[x] = -1;
    O << dp[x] << '\n';
    return 0;
}
