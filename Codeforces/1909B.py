from typing import List


def solve(n: int, a: List[int]) -> int:
    result = 2
    while result <= 10**18:
        has_even = any(el % 2 == 0 for el in a)
        has_odd = any(el % 2 == 1 for el in a)
        if has_even and has_odd:
            break
        for i in range(n):
            a[i] //= 2
        result *= 2
    return result


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = a.copy()
        result = solve(n, b)
        print(result)
