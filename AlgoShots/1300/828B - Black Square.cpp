#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m, i, j, ans = 0, c = 0;
    cin >> n >> m;
    char mat[n][m];
    int rows[n] = {0};
    int columns[m] = {0};
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'B')
                ++rows[i], ++columns[j], ++c;
        }            
    int maxR = -1, maxC = -1, minR = -1, minC = -1;
    for (i = n - 1; i >= 0; --i)
        if (rows[i])
            break;
    maxR = i;
    for (i = m - 1; i >= 0; --i)
        if (columns[i])
            break;
    maxC = i;
    for (i = 0; i < n; ++i)
        if (rows[i])
            break;
    minR = i;
    for (i = 0; i < m; ++i)
        if (columns[i])
            break;
    minC = i;
    int M = max(maxR - minR, maxC - minC) + 1;
    if (M > n or M > m)
        ans = -1;
    else if (c == 0)
        ans = 1;
    else
    {
        ans = M * M - c;
    }
    // cout << minR << ' ' << maxR << '\n' << minC << ' ' << maxC << '\n';
    cout << ans << '\n';
    return 0;
}