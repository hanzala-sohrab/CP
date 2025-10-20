def solve(n: int, k: int):
    if k == n * n - 1:
        print("no")
        return

    print("yes")

    t = k

    for i in range(n):
        for j in range(n):
            if t > 0:
                t -= 1
                print("U", end="")
            elif i == n - 1:
                print("L" if j == n - 1 else "R", end="")
            else:
                print("D", end="")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        solve(n, k)
