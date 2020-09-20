#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    string s;
    I>>s;
    ll i, x, l = s.size(), U = 0;
    F(i,0,l-1)
        if (isupper(s[i]))
            ++U;
    x = U;
    F(i,0,l-1)
    {
        if (islower(s[i]))
            ++U;
        else
            --U;
        x = min(x, U);
    }
    O<<x<<'\n';
    // O<<U<<'\n'<<L<<'\n';
    return 0;
}