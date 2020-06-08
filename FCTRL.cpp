#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define M 1000000007



int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    ll t,n,q,i,j;
    cin>>t;
    while (t--)
    {
        cin>>n;
        ll p=5,z=0;
        for (i=1;i<=n;++i)
        {
            if (n/p==0)
                break;
            z+=n/p;
            p*=5;
        }
        cout<<z<<'\n';
    }
}