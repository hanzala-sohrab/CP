from typing import List


def solve(n: int, a: List[int], b: List[int]):
    mx = mn = 0
    for i in range(n):
        new_mx = max(mx - a[i], b[i] - mn)
        new_mn = min(mn - a[i], b[i] - mx)
        mx, mn = new_mx, new_mn
    print(mx)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        solve(n, a, b)
