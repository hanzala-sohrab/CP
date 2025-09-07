#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(), x.end()

int f(V<V<int>> &a, int k, int ind, V<int> &dp)
{
    if (ind == a.size())
        return k;

    if (dp[ind] != -1)
        return dp[ind];

    int b = 0;

    if (a[ind][0] <= k and k <= a[ind][1])
        b = f(a, max(k, a[ind][2]), ind + 1, dp);

    int c = f(a, k, ind + 1, dp);

    return dp[ind] = max(b, c);
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    ll t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        V<int> dp(1e5 + 1, -1);
        I >> n >> k;
        V<V<int>> a(n, {0, 0, 0});
        F(i, 0, n - 1)
        {
            I >> a[i][0];
            I >> a[i][1];
            I >> a[i][2];
        }
        sort(all(a));
        f(a, k, 0, dp);
        O << max(*max_element(all(dp)), 0) << '\n';
    }
    return 0;
}
