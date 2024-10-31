#include <bits/stdc++.h>
using namespace std;
#define I cin
#define O cout

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t, a, b;
    I >> t;
    while (t--)
    {
        I >> a >> b;
        if (a >= b)
        {
            O << a << '\n';
            continue;
        }
        int ans = 2 * a - b;
        O << (ans <= 0 ? 0 : ans) << '\n';
    }
    return 0;
}
