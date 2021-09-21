#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    long long i, n = s.size(), ans = 1, t = 1;
    for (i = 1; i < n; ++i)
        if (s[i] == s[i - 1])
            ++t;
        else
        {
            ans = max(ans, t);
            t = 1;
        }
    ans = max(ans, t);
    cout << ans;
    return 0;
}
