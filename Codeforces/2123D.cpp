#include <bits/stdc++.h>
using namespace std;
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
        int i, n, k, c1;
        string s;
        I >> n >> k >> s;

        c1 = count(all(s), '1');

        O << (c1 <= k ? "alice" : (n >= 2 * k ? "bob" : "alice")) << '\n';
    }
    return 0;
}
