#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    string s;
    I>>s;
    ll i, l = s.size(), c = 0, t = 0, ans = 0, x = 0;
    F(i,0,l-2)
        if (s[i] == 'v' and s[i + 1] == 'v')
            ++x;
    F(i,0,l-2)
        if (s[i] == 'v' and s[i + 1] == 'v')
            ++c;
        else if (s[i] == 'o')
            ans += c * (x - c);
    O<<ans<<'\n';
    return 0;
}