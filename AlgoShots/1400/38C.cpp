#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, i, j, a, m = 0;
    cin >> n >> l;
    int b[n];
    for (i = 0; i < n; ++i)
        cin >> b[i];
    for (i = l; i < 101; ++i)
    {
        a = 0;
        for (j = 0; j < n; ++j)
            a += b[j] / i;
        m = max(m, a * i);
    }
    cout << m << '\n';
    return 0;
}