/*
    Answer = (floor(N / 2) + 1) * ceil(N / 2)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, j, ans = 0;
    I >> n;
    i = (n / 2) + 1;
    j = ceil(n / 2.0);
    ans = i * j;
    O << ans << '\n';
    return 0;
}
