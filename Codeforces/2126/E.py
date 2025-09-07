import math

def is_possible(n, p, s):
    if p[n - 1] != s[0]:
        return False

    for i in range(1, n):
        if p[i - 1] % p[i] != 0 or s[i] % s[i - 1] != 0:
            return False

    a = [math.lcm(p[i], s[i]) for i in range(n)]

    g = a[0]
    for i in range(1, n):
        g = math.gcd(g, a[i])
        if g != p[i]:
            return False

    g = a[n - 1]
    for i in range(n - 2, -1, -1):
        g = math.gcd(g, a[i])
        if g != s[i]:
            return False

    return True


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        s = list(map(int, input().split()))

        print("yes" if is_possible(n, p, s) else "no")
