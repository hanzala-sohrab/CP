import math


def is_possible(n: int, p: list[int], s: list[int]) -> bool:
    g = s[0]

    if p[n - 1] != g:
        return False

    for i in range(n, 1):
        if s[i] % s[i - 1] != 0 or p[i - 1] % p[i] != 0:
            return False

    a = [math.lcm(p[i], s[i]) for i in range(n)]

    if p[0] != a[0] or s[n - 1] != a[n - 1]:
        return False

    gi = a[0]
    for i in range(1, n):
        gi = math.gcd(gi, a[i])
        if gi != p[i]:
            return False

    gi = a[n - 1]
    for i in range(n - 2, -1, -1):
        gi = math.gcd(gi, a[i])
        if gi != s[i]:
            return False

    return True


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        s = list(map(int, input().split()))
        print("yes" if is_possible(n, p, s) else "no")
