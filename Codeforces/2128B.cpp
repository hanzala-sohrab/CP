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
    int t;
    I >> t;
    while (t--)
    {
        int i, j, k, n;
        I >> n;
        V<int> p(n);
        F(i, 0, n - 1)
        {
            I >> p[i];
        }

        string res = "";

        j = 0;
        k = n - 1;

        F(i, 1, n)
        {
            if (i & 1)
            {
                if (p[j] > p[k])
                {
                    res += "L";
                    ++j;
                }
                else
                {
                    res += "R";
                    --k;
                }
            }
            else
            {
                if (p[j] < p[k])
                {
                    res += "L";
                    ++j;
                }
                else
                {
                    res += "R";
                    --k;
                }
            }
        }

        O << res << '\n';
    }
    return 0;
}
