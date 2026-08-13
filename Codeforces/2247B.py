def main():
    t = int(input())
    for _ in range(t):
        n, k, m = map(int, input().split())
        if m < k:
            print("no")
            continue
        
        a = [1] * n
        a[0] = m - k + 1
        print("yes")
        print(*a)

if __name__ == "__main__":
    main()
