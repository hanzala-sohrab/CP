/*
    * 251A - Points on Line
    * 
    * Select the rightmost point of our triplet.
    * In order to do this we can iterate over all points in ascending order of their X-coordinate.
    * At the same time we'll maintain a pointer to the leftmost point which lays on the distance not greater than d from the current rightmost point.
    * We can easily find out the number of points in the segment between two pointers, excluding the rightmost point.
    * Let's call this number k. Then there exist exactly k * (k - 1) / 2 triplets of points with the fixed rightmost point.
    * The only thing left is to sum up these values for all rightmost points.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define V vector
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll ans = 0, n, d, i, j, k;
    I>>n>>d;
    V<ll>x(n);
    F(i,0,n-1)
        I>>x[i];
    j = n - 1;
    while (j >= 0)
    {
        i = lower_bound(all(x), x[j] - d) - x.begin();
        k = j - i;
        ans += (k * (k - 1)) / 2;
        --j;
    }
    O<<ans<<'\n';
    return 0;
}
