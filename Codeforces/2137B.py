def f(p: list[int], n: int) -> list[int]:
    M = n + 1
    q = [M - i for i in p]
    return q


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        q = f(p, n)
        print(*q)

