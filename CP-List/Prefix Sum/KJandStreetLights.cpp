/*
KJ and street lights
--------------------
Use scanline algorithm

For every 'x', find 'L' = 'x' - 'r' and 'R' = 'x' + 'r'
If 'L' < 0, then 'L' = 0
If 'R' > 'p', then 'R' = 'p'
Create an array of size 'p' + 1 and make every element 0
For every calculated value of 'L' and 'R', ++coor[L] and --coor[R + 1]
Next, create prefix sum array from coor (coor[i + 1] += coor[i])
Finally, find the maximum number of consecutive 0s in the prefix sum array.
*/
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
    ll n, p, i, j, x, r;
    I >> n >> p;
    V<ll> coor(p+1, 0);
    F(i,0,n-1)
    {
        I>>x>>r;
        ll L = x - r, R = x + r;
        L = L < 0 ? 0 : L;
        R = R > p ? p : R;
        ++coor[L];
        --coor[R + 1];
    }
    F(i, 0, p - 1)
        coor[i + 1] += coor[i];
    F(i,0,p)
        coor[i] = coor[i] > 1 ? 0 : coor[i];
    ll m = 0, count = 0;
    F(i,0,p)
    {
        while (i <= p and coor[i] == 0)
        {
            ++i;
            ++count;
        }
        m = max(count, m);
        count = 0;
    }
    O << m << '\n';
    return 0;
}
