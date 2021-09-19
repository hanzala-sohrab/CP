#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n;
vector<ll> x;

void input() {
    cin >> n;
    x.resize(n);
    for (ll i = 0; i < n; ++i)
        cin >> x[i];
}

void output() {
    ll h, i, j;
    ll dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (h = 0; h < n; ++h)
    {
        for (i = 0, j = h; j < n; ++i, ++j)
        {
            ll a = (i + 2 <= j ? dp[i + 2][j] : 0);
            ll b = (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0);
            ll c = (i <= j - 2 ? dp[i][j - 2] : 0);
            dp[i][j] = max(x[i] + min(a, b), x[j] + min(b, c));
        }
    }
    cout << dp[0][n - 1] << '\n';
}

int main() {
    input();
    output();
    return 0;
}