def is_possible() -> bool:
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if a[n - 1] != b[n - 1]:
        return False

    for idx, val in enumerate(reversed(a)):
        i = n - idx - 1
        if i == n - 1 or val == b[i] or val ^ a[i + 1] == b[i] or val ^ b[i + 1] == b[i]:
            continue
        return False
    return True


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print("yes" if is_possible() else "no") 
