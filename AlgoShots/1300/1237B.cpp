#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i, j, a[n], b[n], c = 0, d = 0;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < n; ++i)
        cin >> b[i];
    bool overtaken = false;
    for (i = 0; i < n; ++i)
        if (a[i] != b[i])
        {
            overtaken = true;
            break;
        }
    if (overtaken)
    {
        unordered_map<int, bool> m;
        for (i = j = 0; i < n and j < n; )
        {
            if (a[i] == b[j])
            {
                ++i;
                ++j;
            }
            else
            {
                if (m.find(a[i]) != m.end())
                    ++i;
                else
                {
                    ++c;
                    m.insert(make_pair(b[j], true));
                    ++j;
                }
            }
        }
    }
    cout << c << '\n';
    return 0;
}