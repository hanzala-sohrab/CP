import bisect
from typing import List

def count_element(a: List[int], target: int) -> int:
    left = bisect.bisect_left(a, target)
    right = bisect.bisect_right(a, target)
    return right - left

def f(n: int, b: List[int]) -> List[int]:
    b.sort()
    a: List[int] = []
    i = 0
    for l in range(n - 1, 0, -1):
        a.append(b[i])
        i += l
    a.append(a[-1])
    return a


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        b = list(map(int, input().split()))
        print(*f(n, b))

