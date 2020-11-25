#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int i, j = -1, k = -1, l = s.size();
        bool f = true;
        for (i = 0; i < l - 1; ++i)
            if (s[i] == '2')
            {
                if (s[i + 1] == '1')
                {
                    f = false;
                    break;
                }
            }
        if (f)
        {
            long long sum = 0;
            for (i = 0; i < l; ++i)
                sum = (sum * 10 + s[i] - 48) % 21;
            if (!sum)
                f = false;
        }
        cout << (f ? "The streak lives still in our heart!\n" : "The streak is broken!\n");
    }
    return 0;
}