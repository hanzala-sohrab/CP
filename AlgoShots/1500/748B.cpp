#include <bits/stdc++.h>
using namespace std;
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    string s, t;
    I>>s>>t;
    int i, j, l = s.size(), a = 0;
    V<char> p(26, '$');
    bool possible = true;
    F(i,0,l-1)
    {
        if (s[i] == t[i] and p[s[i] - 97] == '$')
        {
            p[s[i] - 97] = t[i];
            continue;
        }
        if (p[s[i]-97] == '$' and p[t[i] - 97] == '$')
        {
            p[s[i] - 97] = t[i];
            p[t[i] - 97] = s[i];
            ++a;
        }
        else if (p[s[i] - 97] != t[i] or p[t[i] - 97] != s[i])
        {
            possible = false;
            break;
        }
    }
    if (!possible)
        O<<"-1\n";
    else
    {
        O<<a<<'\n';
        if (a)
            F(i,0,25)
                if (p[i] != '$' and (char)(i + 97) < p[i])
                    O<<(char)(i + 97)<<' '<<p[i]<<'\n';
    }
    return 0;
}