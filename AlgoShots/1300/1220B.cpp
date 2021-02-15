
/*
Let's note that (xy)⋅(xz) / (yz)=x2 if x,y,z>0. In this problem n≥3, so we can get each value this way.
*/
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
    ll n, i, j;
    I >> n;
    V<V<ll>> M(n, V<ll>(n));
    F(i,0,n-1)
        F(j,0,n-1)
            I >> M[i][j];
    F(i,0,n-1)
    {
        M[i][i] = (M[i][(i + 1 + n) % n] * M[i][(i - 1 + n) % n]) / M[(i - 1 + n) % n][(i + 1 + n) % n];
        O << (ll)sqrt(M[i][i]) << ' ';
    }
    return 0;
}
