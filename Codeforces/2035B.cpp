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
        int i, n;
        I >> n;
        if (n == 1 or n == 3)
        {
            O << "-1\n";
            continue;
        }
        F(i, 1, n - 4)
        {
            O << 3;
        }
        if (n > 3)
        {
            O << (n & 1 ? "63" : "33");
        }
        O << "66\n";
    }
    return 0;
}
