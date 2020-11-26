#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int i, l = s.size();
    map<char, int> m;
    for (i = 0; i < l; ++i)
        ++m[s[i]];
    int M = 0, ch;
    for (auto it: m)
        if (it.second > M)
        {
            M = it.second;
            ch = it.first;
        }
    cout << (char)ch << ' ' << m[ch] << '\n';
    return 0;
}