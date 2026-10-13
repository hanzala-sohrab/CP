from collections import Counter


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        cnt = Counter()
        for el in a:
            x = el
            y = 2
            while y * y <= x:
                while x % y == 0:
                    cnt[y] += 1
                    x //= y
                y += 1
            if x > 1:
                cnt[x] += 1
        possible = True
        for val in cnt.values():
            if val % n != 0:
                possible = False
                break
        print("YES" if possible else "NO")


if __name__ == "__main__":
    main()
