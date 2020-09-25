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
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        ll sum = (n * (n + 1)) / 2;
        if (n == 3)
        {
            O<<"2\n";
            continue;
        }
        else if (sum & 1)
        {
            O<<"0\n";
            continue;
        }
        i = (sqrt(1 + 4 * sum) - 1) / 2;
        q = n - i;
        if (i * (i + 1) != sum)
            O<<q<<'\n';
        else if (i * (i + 1) == sum)
        {
            q += (i * (i - 1)) / 2 + ((n - i) * (n - i - 1)) / 2;
            O<<q<<'\n';
        }
    }
    return 0;
}