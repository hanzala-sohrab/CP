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
    int n;
    I >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
      I >> a[i];
    }

    int score1 = 0;
    int score2 = 0;

    int maxEl = 0;

    for (int i = 0; i < n; i += 2) {
      maxEl = max(maxEl, a[i]);
      ++score1;
    }
    score1 += maxEl;

    maxEl = 0;
    for (int i = 1; i < n; i += 2) {
      maxEl = max(maxEl, a[i]);
      ++score2;
    }
    score2 += maxEl;

    O << max(score1, score2) << '\n';
  }
  return 0;
}
