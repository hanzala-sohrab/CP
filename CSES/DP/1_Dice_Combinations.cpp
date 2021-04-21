#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, j, k, l;
    I >> n;
    V<ll> dp((M - 7) / 1000 + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    F(i, 7, n)
        dp[i] = (2 * dp[i - 1] - dp[i - 1 - 6] + M) % M;
    O << dp[n] << '\n';
    return 0;
}
