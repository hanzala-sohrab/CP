#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

ll binpow(ll a, ll b) {
    a %= M;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll q, i, n, x, c;
    I>>q;
    while (q--)
    {
        I>>n;
        x = n;
        c = 0;
        string s;
        while (x)
        {
            s = to_string(x % 3) + s;
            if (x % 3 == 2)
                ++c;
            x /= 3;
        }
        if (c == 0)
            O << n << '\n';
        else
        {
            ll l = s.size();
            F(i,0,l-1)
                if (s[i] == '2')
                    break;
            ll j;
            F(j,i,l-1)
                s[j] = '0';
            c = 1;
            for (j = i - 1; j >= 0; --j)
            {
                if (s[j] == '0' and c)
                {
                    s[j] = '1';
                    c = 0;
                }
                else if (s[j] == '1' and c)
                    s[j] = '0';
            }
            if (c)
                s = "1" + s;
            else
                --l;
            F(j, 0, i)
                if (s[j] == '1')
                    x += binpow(3, l - j);
            O << x <<'\n';
        }
    }
    return 0;
}