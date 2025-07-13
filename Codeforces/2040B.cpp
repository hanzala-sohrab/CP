#include <bits/stdc++.h>
using namespace std;
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
        int n;
        I >> n;

        if (n < 3)
        {
            O << n << '\n';
            continue;
        }

        int q = 1;
        int i, j = 0;

        do
        {
            i = 2 * (j + 2) - 1;
            j = i;
            ++q;
        } while (i < n - 1);

        O << q << '\n';
    }
    return 0;
}
