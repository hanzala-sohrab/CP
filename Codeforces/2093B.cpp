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
        string n;
        I >> n;

        int c = 0;

        const int N = n.size();

        int i, j = -1;

        for (i = N - 1; i >= 0; --i)
        {
            if (n[i] != '0')
            {
                j = i;
                break;
            }
            ++c;
        }

        F(i, 0, j - 1)
        {
            if (n[i] != '0')
            {
                ++c;
            }
        }

        O << c << '\n';
    }
    return 0;
}
