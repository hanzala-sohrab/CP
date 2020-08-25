#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout

int main() {
    string s;
    I>>s;
    ll i, l = s.size();
    char c = 'a';
    for (i = 0; i < l and c <= 'z'; ++i)
    {
        if (s[i] > c)
            continue;
        if (s[i] < c)
            s[i] = c;
        ++c;
    }
    if (c > 'z')
        O<<s<<'\n';
    else
        O << "-1\n";
    return 0;
}