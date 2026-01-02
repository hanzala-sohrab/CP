from typing import List
from math import gcd


def solve(n: int, w: int, h: int, d: int) -> List[int]:
    p = w * h * d
    if p % n != 0:
        return [-1]
    wc = gcd(n, w)
    nw = n // wc

    hc = gcd(nw, h)
    nh = nw // hc

    dc = gcd(nh, d)
    nd = nh // dc

    if nd != 1:
        return [-1]

    return [wc - 1, hc - 1, dc - 1]


if __name__ == "__main__":
    t = 1
    for _ in range(t):
        w, h, d = map(int, input().split())
        n = int(input())
        print(*solve(n, w, h, d))
