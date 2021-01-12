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
    ll t,n,q,i,j,k;
    I>>n;
    V<ll>a(n);
    string ans;
    F(i,0,n-1)
        I>>a[i];
    j = 0;
    k = n - 1;
    F(i,1,n)
    {
        if (a[j] == i)
        {
            ans += "L";
            ++j;
        }
        else if (a[k] == i)
        {
            ans += "R";
            --k;
        }
    }
    O<<ans.size()<<'\n'<<ans<<'\n';
    O<<'\n';
    return 0;
}
