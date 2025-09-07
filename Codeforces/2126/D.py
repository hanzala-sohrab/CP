def maximum_coins(data: list[list[int]], current_number_of_coins: int, casino_idx: int, dp: list[int]) -> int:
    if casino_idx == len(data):
        return current_number_of_coins

    if dp[casino_idx] != -1:
        return dp[casino_idx]

    l, r, real = data[casino_idx]

    choose_this_casino = 0
    if l <= current_number_of_coins and current_number_of_coins <= r and current_number_of_coins < real:
        choose_this_casino = maximum_coins(data, real, casino_idx + 1, dp)
    
    reject_this_casino = maximum_coins(data, current_number_of_coins, casino_idx + 1, dp)

    dp[casino_idx] = max(choose_this_casino, reject_this_casino)

    return dp[casino_idx]


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        data = [0] * n
        for i in range(n):
            l, r, real = map(int, input().split())
            data[i] = [l, r, real]

        data.sort()
        dp = [-1] * (n + 1)
        maximum_coins(data, k, 0, dp)
        ans = max(0, max(dp))
        print(ans)
