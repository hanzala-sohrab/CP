int Solution::firstMissingPositive(vector<int> &A) {
    int i, n = A.size(), ans = n + 1;
    vector<int> f(n + 1, 0);
    for (i = 0; i < n; ++i)
        if (A[i] > 0 and A[i] <= n)
            ++f[A[i]];
    for (i = 1; i <= n; ++i)
        if (f[i] == 0)
            return i;
    return ans;
}