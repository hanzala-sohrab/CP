def solve():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        gcd = k + 1
        a = [el + k * (el % gcd) for el in a]
        print(*a)


if __name__ == "__main__":
    solve()
