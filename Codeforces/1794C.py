def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        res = [1]
        d = 1
        for i in range(1, n):
            if a[i - d] > d:
                d += 1
            res.append(d)
        print(*res)


if __name__ == "__main__":
    main()
