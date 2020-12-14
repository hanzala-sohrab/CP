#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, N, Q;
	cin >> N;
	vector<int> a(N), sum(N, 0);
	for (i = 0; i < N; ++i)
	{
		cin >> a[i];
		sum[i] = i ? a[i] + sum[i - 1] : a[0];
	}
	cin >> Q;
	for (k = 0; k < Q; ++k)
	{
		cin >> i >> j;
		cout << (i ? sum[j] - sum[i - 1] : sum[j]) << '\n';
	}
	return 0;
}