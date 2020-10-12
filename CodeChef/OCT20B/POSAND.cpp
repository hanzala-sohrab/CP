#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

bool isPowerOfTwo (ll x) {
    return x && (!(x&(x-1)));
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,q,i,j,k;
    I>>t;
    while (t--)
    {
        I>>n;
        if (n == 1)
        {
            O<<"1\n";
            continue;
        }
        if (isPowerOfTwo(n))
        {
            O<<"-1\n";
            continue;
        }
        O<<"2 3 1 ";
        F(i,3,n-1)
            if (isPowerOfTwo(i + 1))
            {
                O<<i + 2<<' '<< i + 1 <<' ';
                ++i;
            }
            else
                O<<i + 1<<' ';
        O<<'\n';
    }
    return 0;
}