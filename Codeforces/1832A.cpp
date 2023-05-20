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
    ll t,i,L;
    I>>t;
    while (t--)
    {
        string s;
        I>>s;
        L = s.size();
        V<ll>cnt(26, 0);
        for (char ch: s) {
            ++cnt[ch - 97];
        }
        bool possible = false;
        F(i,1,L/2) {
            if (cnt[s[i] - 97] > 1 and s[i] != s[i - 1]) {
                possible = true;
                break;
            }
        }
        O << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
