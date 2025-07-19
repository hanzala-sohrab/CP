#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t, n, q, i, j, k;
    I >> t;
    while (t--)
    {
        I >> n;
        V<int> a(n + 1, 0), b(n, 0);
        queue<int> q;
        F(i, 0, n - 1)
        {
            I >> j;
            if (!a[j])
            {
                b[i] = j;
                a[j] = 1;
            }
        }
        F(i, 1, n)
        {
            if (!a[i])
            {
                q.push(i);
            }
        }
        F(i, 0, n - 1)
        {
            if (!b[i])
            {
                if (!q.empty())
                {
                    b[i] = q.front();
                    q.pop();
                }
            }
        }

        F(i, 0, n - 1)
        {
            O << b[i] << ' ';
        }

        O << '\n';
    }
    return 0;
}
