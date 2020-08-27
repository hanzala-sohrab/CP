#include <bits/stdc++.h>
#include<sstream>
using namespace std;
#define ll long long int
#define I cin
#define O cout

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    string s,o,t;
    I>>s;
    ll l = s.size(), n;
    stringstream ss(s);
    ss >> n;
    t = to_string(n);
    if (l <= 3 and -128 <= n and n <= 127)
        o="byte";
    else if (l <= 5 and -32768 <= n and n <= 32767)
        o="short";
    else if (l <= 10 and -2147483648 <= n and n <= 2147483647)
        o="int";
    else if (l <= 19 and -9223372036854775808 <= n and n <= 9223372036854775807 and t == s)
        o="long";
    else
        o="BigInteger";
    O<<o<<'\n';
    return 0;
}