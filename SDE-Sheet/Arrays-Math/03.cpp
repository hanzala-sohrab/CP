#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        long long s = (n * 1L * (n + 1)) / 2, x = 0;
        int i, y = 0;
        for (i = 0; i < n; ++i)
            x += arr[i];
        for (i = 0; i < n; ++i)
            arr[(arr[i] - 1) % n] += n;

        for (i = 0; i < n; ++i)
            if (arr[i] <= n)
            {
                y = i + 1;
                break;
            }
        int *ans = (int *)malloc(2 * sizeof(int));
        ans[0] = x + y - s;
        ans[1] = y;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
