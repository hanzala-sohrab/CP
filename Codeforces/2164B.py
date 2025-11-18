def main(n, a):
    even = [i for i in a if i % 2 == 0]
    if len(even) > 1:
        print(even[0], even[1])
        return
    L = len(a)
    i = 0
    while i < L:
        j = i + 1
        x = a[i]
        while j < L:
            y = a[j]
            if (y % x) % 2 == 0:
                print(x, y)
                return
            j += 1
        i += 1
    print(-1)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        main(n, a)
