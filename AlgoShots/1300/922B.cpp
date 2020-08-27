#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    int n,a,b,c,ans=0;
    I>>n;
    F(a,1,n-2)
        F(b,a+1,n-1)
        {
            c = a ^ b;
            if (b <=c and c <= n and a + b > c and a + c > b and b + c > a)
                ++ans;
        }
    O<<ans;
    return 0;
}
