#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, i, j, k;
		cin >> n;
		int a[n];
		for (i = 0; i < n; ++i)
			cin >> a[i];
		if (n == 1)
		{
			cout << a[0] << '\n';
			continue;
		}
		if (n & 1)
			for (k = 0, i = 0, j = n - 1; k < n; ++k)
			{
				if (k & 1)
				{
					cout << a[j] << ' ';
					--j;
				}
				else
				{
					cout << a[i] << ' ';
					++i;
				}
			}
		else
			for (k = 0, i = 0, j = n - 1; k < n; ++k)
			{
				if (k & 1)
				{
					cout << a[j] << ' ';
					--j;
				}
				else
				{
					cout << a[i] << ' ';
					++i;
				}
			}
		// for (i = 0; i < n; ++i)
		// 	cout << b[i] << ' ';
		cout << '\n';
	}
	return 0;
}