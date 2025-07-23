#include <bits/stdc++.h>
using namespace std;
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int i, j, k, n, q;
        I >> n >> k;
        i = 1;
        j = n;

        while (j >= i)
        {
            F(q, 1, k - 1)
            {
                if (j < i)
                {
                    break;
                }
                O << j << ' ';
                --j;
            }
            if (i <= j)
            {
                O << i << ' ';
            }
            ++i;
        }

        O << '\n';
    }
    return 0;
}
