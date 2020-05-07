#include <bits/stdc++.h>
using namespace std;
int main () {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		bool val = false;
		if (a1 == a2 && b1 + b2 == a1)
			val = true;
		else if (a1 == b2 && a2 + b1 == a1)
			val = true;
		else if (a2 == b1 && a1 + b2 == a2)
			val = true;
		else if (b1 == b2 && a1 + a2 == b1)
			val = true;
		if (val)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
