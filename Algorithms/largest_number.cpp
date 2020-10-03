bool foo(string a, string b) {
    if (a + b < b + a)
        return true;
    return false;
}

string Solution::largestNumber(const vector<int> &A) {
    int i, n = A.size();
    vector<string> a(n);
    for (i = 0; i < n; ++i)
        a[i] = to_string(A[i]);
    sort(a.begin(), a.end(), foo);
    string s;
    for (i = n - 1; i >= 0; --i)
    {
        s += a[i];
    }
    // string ans;
    i = 0;
    while (i < n and s[i] == '0')
        ++i;
    if (i == n)
        s = "0";
    return s;
}