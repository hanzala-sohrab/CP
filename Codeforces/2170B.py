from typing import List


def solve(n: int, b: List[int]):
    s = sum(b)
    c = len([x for x in b if x > 0])
    print(min(s - (n - 1), c))


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        b = list(map(int, input().split()))
        solve(n, b)
