def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        p = 1
        for el in a:
            p *= el

        left, right = 1, p
        found = False

        while left <= right:
            mid = (left + right) // 2
            power = mid ** n

            if power == p:
                found = True
                break
            elif power < p:
                left = mid + 1
            else:
                right = mid - 1

        print("YES" if found else "NO")


if __name__ == "__main__":
    main()
