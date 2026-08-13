def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        if n == 2:
            print(-1)
            continue
        if n == 1:
            print(1)
            continue
        a = [1, 2, 3]
        s = 6
        for i in range(3, n):
            a.append(s)
            s *= 2
        print(*a)

if __name__ == "__main__":
    main()
