def is_possible():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if a[n - 1] != b[n - 1]:
        return False

    for i in range(n - 2, -1, -1):
        c = a[i] ^ b[i]
        if a[i] == b[i] or c in [a[i + 1], b[i + 1]]:
            continue

        return False

    return True

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print("yes" if is_possible() else "no")
