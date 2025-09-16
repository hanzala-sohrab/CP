from collections import deque

def longest_neat_subsequence_length(a: list[int], n: int):
	MAXX = n + 1
	dp = [0] * MAXX
	dq = [deque() for _ in range(MAXX)]
	for i in range(1, n + 1):
		dp[i] = dp[i - 1]
		dq[a[i - 1]].append(i)
		if len(dq[a[i - 1]]) > a[i - 1]:
			dq[a[i - 1]].popleft()
		if len(dq[a[i - 1]]) == a[i - 1]:
			dp[i] = max(dp[i], dp[dq[a[i - 1]].popleft() - 1] + a[i - 1])
	return dp[n]


if __name__ == "__main__":
	t = int(input())
	for _ in range(t):
		n = int(input())
		a = list(map(int, input().split()))
		print(longest_neat_subsequence_length(a, n))
