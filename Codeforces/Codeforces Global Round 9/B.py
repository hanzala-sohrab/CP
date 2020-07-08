t = int(input())
for l in range(t):
    n, m = map(int, input().split())
    grid = []
    for i in range(n):
        a = list(map(int, input().split()))
        grid.append(a)
    possible = True
    c = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] != 0:
                c += 1
    if c == 0:
        print("YES")
        for i in range(n):
            a = grid[i]
            print(*a, sep=' ')
        continue
    if grid[0][0] > 2 or grid[0][m - 1] > 2 or grid[n - 1][0] > 2 or grid[n - 1][m - 1] > 2:
        possible = False
    if not possible:
        print("NO")
        continue
    m -= 1
    n -= 1
    grid[0][0] = grid[0][m] = grid[n][0] = grid[n][m] = 2
    for i in range(1, m + 1):
        if grid[0][i] > 3 or grid[n][i] > 3:
            possible = False
            break
        grid[0][i] = grid[n][i] = 3
    if not possible:
        print("NO")
        continue
    for i in range(1, n):
        if grid[i][0] > 3 or grid[i][m] > 3:
            possible = False
            break
        grid[i][0] = grid[i][m] = 3
    if not possible:
        print("NO")
        continue
    for i in range(1, n):
        for j in range(1, m):
            if grid[i][j] > 4:
                possible = False
                break
            grid[i][j] = 4
        if not possible:
            break
    if not possible:
        print("NO")
        continue
    print("YES")
    grid[0][m] = grid[n][m] = 2
    for i in range(n + 1):
        a = grid[i]
        print(*a, sep=' ')