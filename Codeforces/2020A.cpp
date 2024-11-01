#include <bits/stdc++.h>
using namespace std;
#define I cin
#define O cout

int main()
{
  I.sync_with_stdio(false);
  I.tie(0);
  int t;
  I >> t;
  while (t--)
  {
    int k, n;
    I >> n >> k;

    if (k == 1)
    {
      O << n << '\n';
      continue;
    }

    int res = 0;
    while (n > 0)
    {
      res += n % k;
      n /= k;
    }

    O << res << '\n';
  }
  return 0;
}
