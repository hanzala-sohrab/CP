#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	long long T, i, j, k, N, Q;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<long long> A(N), sum(N, 0);
		for (i = 0; i < N; ++i)
		{
			cin >> A[i];
			if (i)
			{
				j = sum[i - 1] / i;
				A[i] = sum[i] = A[i] == -1 ? j : A[i];
				sum[i] += sum[i - 1];
			}
			else
				sum[i] = A[i];
		}
		for (i = 0; i < N; ++i)
			cout << A[i] << ' ';
		cout << '\n';
	}
	return 0;
}