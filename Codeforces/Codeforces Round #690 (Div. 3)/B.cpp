#include <bits/stdc++.h>
using namespace std;

string possible(string s, int l) {
	bool val = false;
	if (l < 4)
		val = false;
	else if (s[0] == '2' and s[1] == '0' and s[2] == '2' and s[3] == '0')
		val = true;
	else if (s[l - 4] == '2' and s[l - 3] == '0' and s[l - 2] == '2' and s[l - 1] == '0')
		val = true;
	else if (s[0] == '2' and s[1] == '0' and s[l - 2] == '2' and s[l - 1] == '0')
		val = true;
	else if (s[0] == '2' and s[1] != '0' and s[l - 3] == '0' and s[l - 2] == '2' and s[l - 1] == '0')
		val = true;
	else if (s[0] == '2' and s[1] == '0' and s[2] == '2' and s[3] != '0' and s[l - 1] == '0')
		val = true;
	return val ? "YES\n" : "NO\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, i, j, k, l;
		cin >> n;
		string s;
		cin >> s;
		l = s.size();
		cout << possible(s, l);
	}
	return 0;
}