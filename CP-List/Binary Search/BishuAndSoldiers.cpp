#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int N, Q, i;
    cin >> N;
    vector<int> power(N), sum(N, 0);
    for (i = 0; i < N; ++i)
    {
        cin >> power[i];
    }
    sort(power.begin(), power.end());
    sum[0] = power[0];
    for (i = 1; i < N; ++i)
        sum[i] = power[i] + sum[i - 1];
    cin >> Q;
    for (i = 0; i < Q; ++i)
    {
        int M;
        cin >> M;
        int num = upper_bound(power.begin(), power.end(), M) - power.begin();
        cout << num << ' ' << sum[num - 1] << '\n';
    }
    return 0;
}