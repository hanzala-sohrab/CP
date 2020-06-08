#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define M 1000000007
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        ll a1, a2, a3, a4, a5, p;
        I>>a1>>a2>>a3>>a4>>a5>>p;
        if (p*(a1+a2+a3+a4+a5) <= 24 * 5)
            O<<"No\n";
        else
            O<<"Yes\n";
    }
    return 0;
}
