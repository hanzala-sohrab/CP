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
    int n, x, y, res = 0;
    I >> n >> x >> y;
    int m = min(x, y);
    res = n / m;
    if (n % m > 0)
    {
      ++res;
    }

    O << res << '\n';
  }
  return 0;
}
