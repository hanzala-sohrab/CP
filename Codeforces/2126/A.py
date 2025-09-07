def f(x: int) -> int:
    m = 1001
    while x > 0:
        r = x % 10
        m = min(m, r)
        x //= 10

    return m


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        x = int(input())
        y = f(x)
        print(y)
