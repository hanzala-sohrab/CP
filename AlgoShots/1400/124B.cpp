#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    ll t,n,q=INT_MAX,i,j,k,f=1;
    I>>n>>k;
    F(i,1,k)
        f *= i;
    V<string>a(n);
    ll b[k];
    F(i,0,k-1)
        b[i] = i;
    ll p[f][k];
    F(i,0,n-1)
        I>>a[i];
    i = 0;
    do
    {
        F(j,0,k-1)
            p[i][j] = b[j];
        ++i;
    } while (next_permutation(b, b + k));
    
    F(i,0,f-1)
    {
        ll mi = INT_MAX, ma = INT_MIN;
        F(j,0,n-1)
        {
            ll num = 0;
            string s = a[j];
            F(t,0,k-1)
                num = num * 10 + s[p[i][t]] - 48;
            mi = min(mi, num);
            ma = max(ma, num);
        }
        q = min(ma - mi, q);
    }
    O<<q<<'\n';
    return 0;
}