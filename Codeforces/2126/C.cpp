#include <bits/stdc++.h>
using namespace std;
#define V vector
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
        int i, j, k, n;
        I >> n >> k;
        V<int> h(n);
        F(i, 0, n - 1)
        {
            I >> h[i];
        }

        int currentHeight = h[k - 1];

        sort(all(h));

        int maxHeight = h[n - 1];

        int waterLevel = 0;
        bool possible = true;

        F(i, 0, n - 1)
        {
            if (h[i] <= currentHeight)
                continue;

            waterLevel += h[i] - currentHeight;

            if (waterLevel > currentHeight)
            {
                possible = false;
                break;
            }

            currentHeight = h[i];
        }
        O << (possible ? "yes" : "no") << '\n';
    }
    return 0;
}
