from typing import List


def solve(n: int, s: str):
    c0 = s.count("0")
    if c0 == 0:
        print(0)
        return
    a: List[int] = [0] * n
    last_index_with_one = -1
    for i in range(n - 1, -1, -1):
        if s[i] == "1":
            last_index_with_one = i
            break
    a[0] = 0 if s[0] == "1" else (n - last_index_with_one)
    m = a[0]
    for i in range(1, n):
        a[i] = 0 if s[i] == "1" else (a[i - 1] + 1)
        m = max(m, a[i])
    print(m)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input().strip()
        solve(n, s)
