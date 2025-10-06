from typing import List

def f(n: int, k: int, a: List[int], b: List[int]) -> int:
    a.sort(reverse=True)
    b.sort()

    i, j = 0, 0

    while j < k and i + b[j] - 1 < n:
        i += b[j]
        a[i - 1] = 0
        j += 1

    return sum(a)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        print(f(n, k, a, b))

