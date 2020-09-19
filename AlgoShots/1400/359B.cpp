#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>n>>k;
    F(i,1,n)
    {
        if (k>0)
            O<<2*i<<' '<<2*i-1<<' ';
        else
            O<<2*i-1<<' '<<2*i<<' ';
        --k;
    }
    return 0;
}