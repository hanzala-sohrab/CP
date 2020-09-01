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
    string s, a = "Ann\n", m = "Mike\n";
    I>>s;
    ll i, n = s.size();
    V<char> mi(n);
    mi[0] = s[0];
    char mini = s[0];
    F(i,1,n-1)
    {
        if (mini >= s[i])
            mini = s[i];
        mi[i] = mini;
    }
    F(i,0,n-1)
        if (s[i] == mi[i])
            O<<m;
        else
            O<<a;
    return 0;
}