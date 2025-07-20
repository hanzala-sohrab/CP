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
        if (n < 5)
        {
            O << "-1\n";
            continue;
        }

        deque<int> d = {1, 3, 5, 4, 2};

        for (int i = 6; i <= n; ++i)
        {
            if (i % 2 == 0) {
                d.push_back(i);
            } else {
                d.push_front(i);
            }
        }

        for (const int v : d)
        {
            O << v << ' ';
        }

        O << '\n';
    }
    return 0;
}
