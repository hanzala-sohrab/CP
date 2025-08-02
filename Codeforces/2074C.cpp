#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mmax(a, b, c) max(a, max(b, c))
#define mmin(a, b, c) min(a, min(b, c))
#define M 1000000007
#define V vector
#define F(a, b, c) for (a = b; a <= c; ++a)
#define I cin
#define O cout
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define found(m, x) (m.find(x) != m.end())

bool isPowerOfTwo(ll x)
{
    return x && (!(x & (x - 1)));
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 6; i * i <= n; i += 6)
        if (n % (i - 1) == 0 || n % (i + 1) == 0)
            return false;
    return true;
}

// https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
ll binpow(ll a, ll b)
{
    a %= M;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned gcd(unsigned u, unsigned v)
{
    auto shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if (u > v)
            std::swap(u, v);
    } while ((v -= u));
    return u << shift;
}

int main()
{
    I.sync_with_stdio(false);
    I.tie(0);
    int t;
    I >> t;
    while (t--)
    {
        int x, y, z, i;
        I >> x;
        V<int> dp(21, -1);
        dp[5] = 3;
        dp[6] = dp[9] = dp[11] = dp[12] = dp[14] = dp[17] = dp[19] = dp[20] = 5;
        dp[10] = dp[13] = dp[18] = 6;
        if (x < 21)
            O << dp[x];
        else if (isPowerOfTwo(x) or isPowerOfTwo(x + 1))
            O << -1;
        else
        {
            string s;
            while (x > 1)
            {
                int r = x % 2;
                s += to_string(1);
                x >>= 1;
            }
            // reverse(all(s));
            // O << s << '\n';
            y = 0;
            F(i, 0, s.size() - 1)
            {
                // O << s[i] - 48 << ' ';
                y += (s[i] - 48) * (1 << i);
            }
            O << y;
        }
        O << '\n';
    }
    return 0;
}
