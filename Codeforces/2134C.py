def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        res = 0

        for i in range(1, n, 2):
            if i + 1 < n:
                b = a[i + 1] + a[i - 1] - a[i]
                if b > 0:
                    res += b
                    a[i + 1] = 0 if a[i - 1] > a[i] else a[i] - a[i - 1]
            elif a[i - 1] > a[i]:
                res += a[i - 1] - a[i]
        print(res)


if __name__ == "__main__":
    solve()
