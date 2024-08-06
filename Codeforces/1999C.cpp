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
  ll t, n, s, m, j;
  I >> t;
  while (t--) {
    I >> n >> s >> m;
    V<V<ll>> i(n);
    F(j, 0, n - 1) {
      ll a, b;
      I >> a >> b;
      i[j] = {a, b};
    }
    sort(all(i), [](V<ll> x, V<ll> y) { return x[0] < y[0]; });
    ll ref = 0;
    bool possible = false;
    F(j, 0, n - 1) {
      if (i[j][0] - ref >= s) {
        possible = true;
        break;
      }
      ref = i[j][1];
    }
    if (possible or m - ref >= s)
      O << "YES\n";
    else
      O << "NO\n";
  }
  return 0;
}
