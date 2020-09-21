#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    ll t,n,q,i,j,k;
    string a;

    I>>a>>k;

    n = a.size();

    if (k >= n)
        F(i,n+1,k)
            a += "$";

    F(i,0,n-1)
    {
        t = a[i] - 48;
        ll m = t, ind = i;

        F(j,i+1,min(n-1,i+k))
        {
            q = a[j] - 48;
            if (q > t and m < q)
            {
                m = q;
                ind = j;
            }
        }

        string s;

        F(j,0,i-1)
            s += a[j];

        s += a[ind];

        F(j,i,min(n-1,ind-1))
            s += a[j];

        F(j,ind+1,n-1)
            s += a[j];

        a = s;

        k -= ind - i;
    }
    O<<a<<'\n';
    return 0;
}