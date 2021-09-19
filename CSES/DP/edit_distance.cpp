#include<bits/stdc++.h>
using namespace std;

string n, m;

void input() {
    cin >> n >> m;
}

void output() {
    int i, j, l1 = n.size(), l2 = m.size();
    int dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= l2; ++i)
        dp[0][i] = i;
    for (i = 1; i <= l1; ++i)
        dp[i][0] = i;
    for (i = 1; i <= l1; ++i)
        for (j = 1; j <= l2; ++j)
            if (n[i - 1] != m[j - 1])
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            else
                dp[i][j] = dp[i - 1][j - 1];
    cout << dp[l1][l2] << '\n';
}

int main() {
    input();
    output();
    return 0;
}