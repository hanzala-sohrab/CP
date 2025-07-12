#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        int i, n, k;

        I >> n >> k;

        vector<int> a(n);

        ll totalNumberOfApples = 0;

        F(i, 0, n - 1)
        {
            I >> a[i];
            totalNumberOfApples += a[i];
        }

        int maxNumberOfApplesInABox = *max_element(all(a));
        int minNumberOfApplesInABox = *min_element(all(a));

        int cM = 0;
        F(i, 0, n - 1)
        {
            if (a[i] == maxNumberOfApplesInABox)
            {
                ++cM;
            }
        }

        if (maxNumberOfApplesInABox - minNumberOfApplesInABox - 1 > k or (maxNumberOfApplesInABox - minNumberOfApplesInABox > k and cM > 1))
        {
            O << "Jerry\n";
        }
        else
        {
            O << (totalNumberOfApples & 1 ? "Tom" : "Jerry") << '\n';
        }
    }
    return 0;
}
