#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (isPowerOfTwo(x) || isPowerOfTwo(x + 1))
        {
            cout << "-1\n";
            continue;
        }

        int result = 0;
        int pos = 0;
        int temp = x;

        while (temp > 1)
        {
            result += (1 << pos);
            temp >>= 1;
            pos++;
        }

        cout << result << '\n';
    }

    return 0;
}
