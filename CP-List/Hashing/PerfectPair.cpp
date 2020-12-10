#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int i, N, ans = 0;
        cin >> N;
        unordered_map<int, int> m;
        vector<int> a;
        for (i = 0; i < N; ++i)
        {
            int j;
            cin >> j;
            if (m.find(j) == m.end())
            {
                m.insert(make_pair(j, 1));
                a.push_back(j);
            }
            else
                ++m[j];
        }
        vector<int> cubesAndSquares(2001, 0);
        for (i = 1; i * i <= 2001; ++i)
        {
            cubesAndSquares[i * i] = 1;
            if (i * i * i <= 2001)
                cubesAndSquares[i * i * i] = 1;
        }
        for (i = 0; i < a.size(); ++i)
        {
            int count = m[a[i]];
            if (count and cubesAndSquares[2 * a[i]])
                ans += (count * (count - 1)) / 2;
            for (int j = i + 1; j < a.size(); ++j)
            {
                int sum = a[i] + a[j];
                if (cubesAndSquares[sum])
                    ans += count * m[a[j]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
