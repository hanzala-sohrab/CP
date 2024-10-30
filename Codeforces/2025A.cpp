#include <bits/stdc++.h>
using namespace std;
#define I cin
#define O cout

int getLengthOfLongestCommonPrefix(string &s, string &t)
{
    const int lenS = s.size();
    const int lenT = t.size();
    int i = 0;
    while (i < min(lenS, lenT) and s[i] == t[i])
    {
        ++i;
    }
    return i;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int q;
    I >> q;
    while (q--)
    {
        string s, t;
        I >> s >> t;
        int longestCommanPrefixLength = getLengthOfLongestCommonPrefix(s, t);
        O << s.size() + t.size() - longestCommanPrefixLength + (longestCommanPrefixLength > 0 ? 1 : 0) << '\n';
    }
    return 0;
}
