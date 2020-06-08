#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

int main() {
    ll n, y1, y2, l1 = 1, r1, l2 = 1, r2, i = 1;
    I >> n;
    r1 = r2 = n;
    y1 = y2 = (l1 + r1) / 2;
    while (1)
    {
        char c;
        if (i & 1)
        {
            O << y1 << '\n';
            I >> c;
            if (c == 'E')
                break;
            if (c == 'L')
                r1 = y1 - 1;
            else
                l1 = y1 + 1;
            y1 = (l1 + r1) / 2;   
        }
        else
        {
            O << y2 << '\n';
            I >> c;
            if (c == 'E')
                break;
            if (c == 'L')
                r2 = y2 - 1;
            else
                l2 = y2 + 1;
            y2 = (l2 + r2) / 2;
        }
        ++i;
    }
    return 0;
}