#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define I cin
#define O cout
#define all(x) x.begin(),x.end()

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll n, i, c = 0, j;
    string s;
    I>>n>>s;
    sort(all(s));
    O<<s<<'\n';
    return 0;
}