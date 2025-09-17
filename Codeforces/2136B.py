def find_permutation(s: str, n: int, k: int):
    cnt = 0
    for i in range(n):
        if s[i] == "1":
            cnt += 1
        else:
            cnt = 0
        if cnt == k:
            print("no")
            return

    a = [0] * n
    j = 1
    for i in range(n):
        if s[i] == "1":
            a[i] = j
            j += 1
    for i in range(n):
        if s[i] == "0":
            a[i] = j
            j += 1

    print("yes")
    print(*a)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        s = input()
        find_permutation(s, n, k)
