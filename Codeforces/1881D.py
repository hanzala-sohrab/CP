from collections import Counter
import sys

input = sys.stdin.readline


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        cnt = Counter()

        for el in a:
            x = el

            while x % 2 == 0:
                cnt[2] += 1
                x //= 2

            d = 3
            while d * d <= x:
                while x % d == 0:
                    cnt[d] += 1
                    x //= d
                d += 2

            if x > 1:
                cnt[x] += 1

        possible = all(val % n == 0 for val in cnt.values())

        print("YES" if possible else "NO")


if __name__ == "__main__":
    main()
