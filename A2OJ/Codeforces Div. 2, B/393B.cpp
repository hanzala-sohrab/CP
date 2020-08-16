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
    I>>n;
    V<V<ll>> w(n, V<ll>(n));
    V<V<double>> a(n, V<double>(n)), b(n, V<double>(n));
    F(i,0,n-1)
        F(j,0,n-1)
        {
            I>>w[i][j];
            if (i == j)
            {
                a[i][j] = w[i][j];
                b[i][j] = 0;
            }
        }
    F(i,0,n-1)
    {
        F(j,0,n-1)
        {
            if (i == j)
                continue;
            a[i][j] = (w[i][j] + w[j][i]) / 2.0;
            b[i][j] = (w[i][j] - w[j][i]) / 2.0;
        }
    }
    F(i,0,n-1)
    {
        F(j,0,n-1)
            printf("%.8f ", a[i][j]);
        printf("\n");
    }
    F(i,0,n-1)
    {
        F(j,0,n-1)
            printf("%.8f ", b[i][j]);
        printf("\n");
    }
    return 0;
}
