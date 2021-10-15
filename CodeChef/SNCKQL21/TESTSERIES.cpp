#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int r[5], i = 0, e = 0, d = 0;
        cin >> r[0] >> r[1] >> r[2] >> r[3] >> r[4];
        for (int x : r)
            if (x == 1)
                ++i;
            else if (x == 2)
                ++e;
            else
                ++d;
        if (e == i)
            cout << "DRAW\n";
        else if (e > i)
            cout << "ENGLAND\n";
        else
            cout << "INDIA\n";
    }
    return 0;
}