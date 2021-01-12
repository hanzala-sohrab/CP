#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll t,n,a,b,c,i;
    I>>t;
    while (t--)
    {
        I>>n;
        ll s = sqrt(n), x = n;
        bool found = false;
        F(a,2,s-1)
            if (n % a == 0)
            {
                n /= a;
                F(b,a+1,s-1)
                    if (n % b == 0)
                    {
                        found = true;
                        break;
                    }
                if (found)
                    break;
            }
        if (found)
        {
            c = x / (a * b);
            if (a != b and b != c and c != a)
                O<<"YES\n"<<a<<' '<<b<<' '<<c<<'\n';
            else
                O<<"NO\n";
        }
        else
            O<<"NO\n";
    }
    return 0;
}
