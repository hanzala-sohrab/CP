#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll i, n, c = 0;
    string a, b;
    I>>n>>a>>b;
    F(i,0,n-1)
    {
        if (a[i] == b[i])
            continue;
        if (i + 1 < n and a[i + 1] == b[i] and b[i + 1] == a[i] and a[i] != a[i + 1])
        {
            c++;
            ++i;
        }
        else
            ++c;
    }
    O << c << '\n';
    return 0;
}