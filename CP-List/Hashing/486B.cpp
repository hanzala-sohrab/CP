/*                          OR in Matrix
                            ------------
    if B[i][j] = 0, then set every element in row 'i' and in column 'j' in A to 0.
    At the end, put 1 in the remaining places.

    Find another matrix C from A by applying the operation mentioned in the problem

    If C != B, then Nam has made a mistake.
    Otherwise, print A.
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int m, n, i, j, k;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n, 1)), B(m, vector<int>(n)), C(m, vector<int>(n, -1));
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            cin >> B[i][j];
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (B[i][j] == 0)
            {
                for (k = 0; k < n; ++k)
                    A[i][k] = 0;
                for (k = 0; k < m; ++k)
                    A[k][j] = 0;
            }
        }
    }
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            int x = 0, y = 0;
            for (k = 0; k < m; ++k)
                if (A[k][j] == 1)
                {
                    x = 1;
                    break;
                }
            for (k = 0; k < n; ++k)
                if (A[i][k] == 1)
                {
                    y = 1;
                    break;
                }
            C[i][j] = x | y;
        }
    }
    bool possible = true;
    for (i = 0; i < m and possible; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (B[i][j] != C[i][j])
            {
                possible = false;
                break;
            }
        }
    }
    if (!possible)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
                cout << A[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
