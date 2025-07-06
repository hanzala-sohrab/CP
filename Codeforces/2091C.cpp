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
        int i, j, n;
        I >> n;

        if (n % 2 == 0)
        {
            O << "-1\n";
            continue;
        }

        j = n;

        F(i, 1, n)
        {
            if (i == 1)
            {
                O << 1 << ' ';
            }
            else
            {
                O << j-- << ' ';
            }
        }

        O << '\n';
    }
    return 0;
}
