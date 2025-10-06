def get(indices, prefix, s):
    i = indices[len(indices) // 2]
    res = 0
    for j in indices:
        if s[i] == "a":
            res += abs(prefix[i][1] - prefix[j][1])
        else:
            res += abs(prefix[i][0] - prefix[j][0])
    return res


def f(s: str, n: int) -> int:
    if n < 4:
        return 0

    ca = s.count("a")
    cb = n - ca

    if ca < 2 or cb < 2:
        return 0

    a_indices = [i for i, ch in enumerate(s) if ch == "a"]
    b_indices = [i for i, ch in enumerate(s) if ch == "b"]

    prefix = [(0, 0) for _ in range(n + 1)]

    prefix[1] = (1, 0) if s[0] == "a" else (0, 1)

    for i in range(1, n):
        ch = s[i]
        ca, cb = prefix[i]
        if ch == "a":
            ca += 1
        else:
            cb += 1
        prefix[i + 1] = (ca, cb)

    ca = s.count("a")
    cb = n - ca

    return min(get(a_indices, prefix, s), get(b_indices, prefix, s))


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        print(f(s, n))
