#include <bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{
    int s = 0, i, dp[n] = {0};
    dp[0] = arr[0];
    for (i = 1; i < n; ++i)
        dp[i] += arr[i] + max(dp[i - 1], 0);
    for (i = 0; i < n; ++i)
        s = max(s, dp[i]);
    return s;
}

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
