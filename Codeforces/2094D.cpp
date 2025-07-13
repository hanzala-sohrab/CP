#include <bits/stdc++.h>
using namespace std;
#define I cin
#define O cout

string compress(string &s)
{
    const int n = s.size();

    int i, c = 1;

    string compressed = "";

    for (i = 0; i + 1 < n; ++i)
        if (s[i] == s[i + 1])
            ++c;
        else
        {
            compressed += string(1, s[i]) + to_string(c);
            c = 1;
        }

    compressed += string(1, s[i]) + to_string(c);

    return compressed;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        string p, s;
        I >> p >> s;

        if (p == s)
        {
            O << "YES\n";
            continue;
        }

        p = compress(p);
        s = compress(s);

        bool possible = true;

        int n = p.size();
        int m = s.size();

        int i = 0, j = 0, cP = 0, cS = 0;

        while (i < n and j < m)
        {
            if (isalpha(p[i]) and isalpha(s[j]))
            {
                if (p[i] != s[j] or cP > cS or cS > 2 * cP or (cP == 0 and cS > 0))
                    break;

                cP = cS = 0;

                ++i;
                ++j;
            }

            if (isdigit(p[i]))
            {
                cP = cP * 10 + (p[i] - 48);
                ++i;
            }

            if (isdigit(s[j]))
            {
                cS = cS * 10 + (s[j] - 48);
                ++j;
            }
        }

        if (i < n or j < m or cP > cS or cS > 2 * cP or (cP == 0 and cS > 0))
        {
            possible = false;
        }

        O << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
