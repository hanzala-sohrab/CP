import sys

input = sys.stdin.buffer.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    s = 0
    seen = {0}
    ans = "NO"

    for i in range(n):
        s += a[i] if i % 2 == 0 else -a[i]

        if s in seen:
            ans = "YES"
            break

        seen.add(s)

    print(ans)
