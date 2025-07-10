#include <bits/stdc++.h>
using namespace std;
#define mmax(a, b, c) max(a, max(b, c))
#define mmin(a, b, c) min(a, min(b, c))
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    V<int> fib = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    while (t--)
    {
        int w, l, h, i, n, m;
        I >> n >> m;

        F(i, 0, m - 1)
        {
            I >> w >> l >> h;

            int minDimension = mmin(l, w, h);
            int maxDimension = mmax(l, w, h);

            int largestCubeSideLength = fib[n];
            int reqdHeight = fib[n + 1];

            O << (minDimension < largestCubeSideLength or maxDimension < reqdHeight ? 0 : 1);
        }
        O << '\n';
    }
    return 0;
}
