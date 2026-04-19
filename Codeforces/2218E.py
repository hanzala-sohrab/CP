def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        ans = 0
        for i in range(n):
            for j in range(n):
                ans = max(ans, a[i] ^ a[j])
        print(ans)


if __name__ == "__main__":
    main()

