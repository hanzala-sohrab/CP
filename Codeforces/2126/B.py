def maximum_number_of_peaks(n: int, k: int, a: list[int]):
    ans = 0
    cnt = 0
    for i in range(n):
        if a[i] == 1:
            ans += (cnt + 1) // k
            cnt = 0
        else:
            cnt += 1
    ans += (cnt + 1) // k
    return ans


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        print(maximum_number_of_peaks(n, k + 1, a))
