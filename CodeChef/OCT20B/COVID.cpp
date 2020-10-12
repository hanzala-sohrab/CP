#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int i, c, n, x, y, k, j = 0;
        cin >> n >> k >> x >> y;
        bool covid = false;
        for (i = 0, c = x; ; ++i)
        {
            if (y == (c + k) % n)
            {
                covid = true;
                break;
            }
            if (c == x)
                ++j;
            if (j == 2)
                break;
            c = (c + k) % n;
        }
        if (covid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}