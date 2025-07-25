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
        int i, n;
        I >> n;
        V<int> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }

        if (n == 1)
        {
            O << "yes\n";
            continue;
        }

        bool possible = true;

        F(i,0,n-1) {
            if (a[i] <= 2 * max(i, n - i - 1)) {
                possible = false;
                break;
            }
        }

        O << (possible ? "yes" : "no") << '\n';
    }
    return 0;
}
