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
        int i, j, n, ans = 0;
        I >> n;
        set<int> curr, seen;
        F(i, 0, n - 1)
        {
            I >> j;
            curr.insert(j);
            seen.insert(j);
            if (curr.size() == seen.size())
            {
                ++ans;
                seen.clear();
            }
        }
        O << ans << '\n';
    }
    return 0;
}
