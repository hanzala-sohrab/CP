#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    long long int i, t;
    cin >> t;
    for (i = 0; i < t; ++i)
    {
        long long int n, c = 0, j, s = 0, m, sum = 0;
        cin >> n;
        s = (n * (n + 1)) / 2;
        if (n == 3)
            c = 2;
        else if (s & 1)
            c = 0;
        else
        {
            m = (sqrt(1 + 4 * s) - 1) / 2;
            c = n - m;
            if (m * (m + 1) == s)
                c += (m * (m - 1)) / 2 + ((n - m) * (n - m - 1)) / 2;
        }
        cout << c << '\n';
    }
    return 0;
}