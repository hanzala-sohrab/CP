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
    int t, n, i, j;
    I >> t;
    while (t--)
    {
        I >> n;
        V<int> a(n);
        F(i, 0, n - 1)
        {
            I >> a[i];
        }
        sort(all(a), greater<int>());
        while (a.size() >= 2)
        {
            i = a.back();
            a.pop_back();
            j = a.back();
            a.pop_back();
            a.push_back((i + j) / 2);
        }
        O << a.back() << '\n';
    }
    return 0;
}
