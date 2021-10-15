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
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 7 or b == 7 or c == 7)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
