def f(a: int, b: int) -> int:
    if a == b:
        print(0)
        return

    n = a.bit_length()
    m = b.bit_length()

    if n < m:
        print(-1)
        return
    if n == m:
        print(1)
        print(a ^ b)
        return

    x = a ^ b
    k = 0

    if x <= a:
        k += 1
        print(k)
        print(x)
        return
    
    ans = []
    t = 1

    while x > 0:
        r = x % 2

        if r == 1:
            ans.append(t)

        t <<= 1

        x >>= 1

    print(len(ans))
    print(*ans)
    

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, b = map(int, input().split())
        f(a, b)
