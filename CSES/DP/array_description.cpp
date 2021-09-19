#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> x;

void input() {
    cin >> n >> m;
    x.resize(n);
    for (int i; i < n; ++i)
        cin >> x[i];
}

void output() {
    int i, j, ans = 0;
    const int M = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (i == 1 and (x[i - 1] == 0 or x[i - 1] == j))
                dp[i][j] = 1;
            else if (x[i - 1] == 0 or x[i - 1] == j)
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % M + dp[i - 1][j + 1]) % M;
        }
    }
    for (i = 1; i <= m; ++i)
        ans = (ans + dp[n][i]) % M;
    
    cout << ans << '\n';
}

int main() {
    input();
    output();
    return 0;
}