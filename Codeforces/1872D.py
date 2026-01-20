from typing import List
import math


def solve(n: int, x: int, y: int) -> int:
    lcm = (x * y) // math.gcd(x, y)
    count1 = (n // x) - (n // lcm)
    count2 = (n // y) - (n // lcm)
    k = n - count1 + 1
    s_x = (n * n + n - k * k + k) // 2
    s_y = (count2 * (count2 + 1)) // 2
    return s_x - s_y


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, x, y = map(int, input().split())
        result = solve(n, x, y)
        print(result)
