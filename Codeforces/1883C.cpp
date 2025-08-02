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
        int i, n, k, j;
        I >> n >> k;
        V<int> a(n);
        F(i, 0, n - 1)
        {
            I >> j;
            a[i] = j % k;
        }
        if (k == 1 or *min_element(all(a)) == 0)
            O << "0\n";
        else if (k == 2 or k == 3 or k == 5)
            O << k - *max_element(all(a));
        else
        {
            int c2 = count(all(a), 2);
            if (c2)
                O << (c2 > 1 ? 0 : 1);
            else if (count(all(a), 3))
                O << 1;
            else
                O << (count(all(a), 1) > 1 ? 2 : 3);
        }
        O << '\n';
    }
    return 0;
}
