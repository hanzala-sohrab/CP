from collections import defaultdict
from random import getrandbits

RD = getrandbits(31)


def make_it_equal():
    _, k = map(int, input().split())
    S = list(map(int, input().split()))
    T = list(map(int, input().split()))

    cnt = defaultdict(int)

    for x in S:
        r = x % k
        cnt[min(r, k - r) ^ RD] += 1
    for y in T:
        r = y % k
        cnt[min(r, k - r) ^ RD] -= 1
    return all(x == 0 for x in cnt.values())


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print("yes" if make_it_equal() else "no")
