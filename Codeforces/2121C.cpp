#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, j, n, m, M = 0, cM = 0;
        I >> n >> m;

        V<V<int>> a(n, V<int>(m));

        F(i, 0, n - 1)
        {
            F(j, 0, m - 1)
            {
                I >> a[i][j];
                M = max(M, a[i][j]);
            }
        }

        V<int> row(n, 0), col(m, 0);
        F(i, 0, n - 1)
        {
            F(j, 0, m - 1)
            {
                if (a[i][j] == M)
                {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        int cnt = 0;
        for (i = j = 0; i < n and j < m; ++i, ++j)
        {
            cnt += row[i] + col[j];
            if (a[i][j] == M)
                --cnt;
        }
        O << (cnt == cM)
    }
    return 0;
}
