from bisect import bisect_left


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        valid = []
        ans = 0
        for i in range(n):
            el = a[i]
            if el < i + 1:
                ans += bisect_left(valid, el)
                valid.append(i + 1)
        print(ans)


if __name__ == "__main__":
    main()
