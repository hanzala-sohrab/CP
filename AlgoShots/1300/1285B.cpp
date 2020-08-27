#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I>>t;
    while (t--)
    {
        int n, i, neg = 0;
        ll s = 0, m = INT_MIN;
        I>>n;
        V<ll>a(n), dp(n), dp1(n - 1), dp2(n - 1);
        F(i,0,n-1)
        {
            I>>a[i];
            s += a[i];
            if (a[i] < 0)
                ++neg;
        }
        dp[0] = dp1[0] = max(0ll, a[0]);
        dp2[0] = max(0ll, a[1]);
        F(i,1,n-1)
        {
            dp[i] = a[i] + max(0ll, dp[i - 1]);
            if (i < n - 1)
            {
                dp1[i] = a[i] + max(0ll, dp1[i - 1]);
                dp2[i] = a[i + 1] + max(0ll, dp2[i - 1]);
            }
        }
        F(i,0,n-2)
            m = mmax(m, dp1[i], dp2[i]);
        if (s > m)
            O<<"YES\n";
        else
            O<<"NO\n";
    }
    return 0;
}