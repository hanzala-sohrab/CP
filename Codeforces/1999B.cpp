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

bool isPowerOfTwo(ll x) { return x && (!(x & (x - 1))); }

// https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-3
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

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned gcd(unsigned u, unsigned v) {
  auto shift = __builtin_ctz(u | v);
  u >>= __builtin_ctz(u);
  do {
    v >>= __builtin_ctz(v);
    if (u > v)
      std::swap(u, v);
  } while ((v -= u));
  return u << shift;
}

int main() {
  I.sync_with_stdio(false);
  I.tie(0);
  ll t, a1, a2, b1, b2;
  I >> t;
  while (t--) {
    I >> a1 >> a2 >> b1 >> b2;
    ll ma = min(a1, a2), Ma = max(a1, a2), mb = min(b1, b2), Mb = max(b1, b2);
    ll ans = 0;
    if (Mb <= ma) {
      ans = 4;
    } else if (ma >= mb) {
      ans = 2;
    }
    if (a1 == a2 and a1 == b1 and b1 == b2) {
      ans = 0;
    }
    O << ans << '\n';
  }
  return 0;
}