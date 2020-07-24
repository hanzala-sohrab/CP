#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F(a,b,c) for (a=b;a<=c;++a)
#define I cin
#define O cout

const ll M = 1e17;

int main() {
    I.sync_with_stdio(false);
    I.tie(0);
    ll k, i, j, l, m, p = 1;
    vector<ll> a(10, 1);
    I >> k;
    bool found = false;
    string s = "codeforces";
    if (k == 1)
        O << s;
    else
        for (i = 0; !found; ++i)
        {
            F(j, 0, 9)
            {
                p = (p * a[j]) % M;
                if (p >= k)
                {
                    found = true;
                    F(l,0,9)
                        F(m,1,a[l])
                            O<<s[l];
                    break;
                }
            }
            ++a[i % 10];
            p = 1;
        }
    O<<endl;
    return 0;
}