#include <bits/stdc++.h>
using namespace std;
#define I cin
#define O cout
#define all(x) x.begin(), x.end()

string sort(string &s)
{
    int countT = count(all(s), 'T');
    string a = "";
    for (int i = 0; i < countT; ++i)
    {
        a += "T";
    }
    string res = "";
    for (char ch : s)
    {
        if (ch != 'T')
        {
            res += string(1, ch);
        }
    }

    return a + res;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        string s;
        I >> s;
        O << sort(s) << '\n';
    }
    return 0;
}
