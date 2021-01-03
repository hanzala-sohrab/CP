/*
    * 485B - Valuable Resources
    * 
    * Sort all 'x' and 'y' values
    * del_X = max_X - min_X
    * del_Y = max_Y - min_Y
    * max_val = max(del_X, del_Y)
    * Answer = max_val ^ 2
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>n;
    V<ll> x(n), y(n);
    F(i,0,n-1)
        I>>x[i]>>y[i];
    sort(all(x));
    sort(all(y));
    ll m = max(x[n - 1] - x[0], y[n - 1] - y[0]);
    O << m * m << '\n';
    return 0;
}
