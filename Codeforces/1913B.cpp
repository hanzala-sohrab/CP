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
        string s;
        I >> s;
        int n = s.size();
        int c0 = count(all(s), '0');
        int c1 = count(all(s), '1');
        if (c0 == 0 or c1 == 0)
        {
            O << n << '\n';
            continue;
        }
        if (c0 == c1)
        {
            O << "0\n";
            continue;
        }
        int i, ans = 0;
        F(i, 0, n - 1)
        {
            if (s[i] == '1')
            {
                if (c0 > 0)
                    --c0;
                else
                    break;
            }
            else
            {
                if (c1 > 0)
                    --c1;
                else
                    break;
            }
        }
        O << n - i << '\n';
    }
    return 0;
}
