t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for j in range(n):
        if j % 2 != 0:
            if a[j] < 0:
                a[j] *= -1
        else:
            if a[j] > 0:
                a[j] *= -1
    print(*a, sep = ' ')