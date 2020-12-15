#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int i, t;
	cin >> t;
	vector<string> ans(51, "-1");
	for (i = 0; i < 10; ++i)
		ans[i] = to_string(i);
	for (i = 10; i < 18; ++i)
		ans[i] = ans[i % 9] + ans[9];
	for (i = 18; i < 25; ++i)
		ans[i] = ans[i % 17] + ans[17];
	for (i = 25; i < 31; ++i)
		ans[i] = ans[i % 24] + ans[24];
	for (i = 31; i < 36; ++i)
		ans[i] = ans[i % 30] + ans[30];
	for (i = 36; i < 40; ++i)
		ans[i] = ans[i % 35] + ans[35];
	for (i = 40; i < 43; ++i)
		ans[i] = ans[i % 39] + ans[39];
	for (i = 43; i < 45; ++i)
		ans[i] = ans[i % 42] + ans[42];
	ans[45] = "1" + ans[44];
	while (t--)
	{
		int x;
		cin >> x;
		cout << ans[x] << '\n';
	}
	return 0;
}