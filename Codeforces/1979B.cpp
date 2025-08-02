#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        int i, x, y;
        I >> x >> y;

        F(i, 0, 31)
        {
            bool iThBitInX = x & (1 << i);
            bool iThBitInY = y & (1 << i);

            if (iThBitInX != iThBitInY)
            {
                O<<(1ll << i) << '\n';
                break;
            }
        }
    }
    return 0;
}
