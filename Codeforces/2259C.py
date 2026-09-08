def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        for i in range(n):
            if a[i] == -1:
                a[i] = 1
            if a[i] == 1:
                break
        for i in range(n - 1, 0, -1):
            if a[i] == -1:
                a[i] = 1
            if a[i] == 1:
                break
        for i in range(n):
            a[i] = max(a[i], 0)

        print(" ".join(map(str, a)))

if __name__ == "__main__":
	main()
