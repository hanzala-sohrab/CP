#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using std::cout;
using std::cin;
using std::vector;
using std::lower_bound;
using std::sort;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    int T, t;
    cin >> T;
    for (t = 0; t < T; ++t)
    {
        int N, X, p, k, i, j = 0, ans = -1;
        cin >> N >> X >> p >> k;
        vector<int> A(N);
        for (i = 0; i < N; ++i)
            cin >> A[i];

        sort(A.begin(), A.end());

        i = lower_bound(A.begin(), A.end(), X) - A.begin();

        if ((i < N and A[i] != X) or i == N)
        {
            A[k - 1] = X;
            sort(A.begin(), A.end());
            j = 1;
        }
        if (A[p - 1] == X)
            ans = 0 + j;
        else
        {
            int l, m = INT_MAX, i;
            for (l = 0; l < N; ++l)
                if (A[l] == X and abs(p - l - 1) < m)
                {
                    m = abs(p - l - 1);
                    i = l + 1;
                }
            if ((i <= p and p <= k) or (i >= p and p >= k))
                ans = abs(p - i) + j;
        }
        cout << ans << '\n';
    }
    return 0;
}