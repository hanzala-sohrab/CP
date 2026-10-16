def increment_char(c: str) -> str:
    if c == "Z":
        return "A"
    elif c == "z":
        return "a"
    else:
        return chr(ord(c) + 1)


def solve(s: str) -> str:
    n = len(s)
    S = list(s)
    if n == 1 or (n == 2 and s[0] != s[1]):
        return s
    if n == 2 and s[0] == s[1]:
        S[1] = increment_char(s[1])
        return "".join(S)
    for i in range(n - 2):
        if S[i] != S[i + 1]:
            continue
        if S[i] == S[i + 2]:
            S[i + 1] = increment_char(S[i])
        elif (S[i] == "a" and S[i + 2] == "z") or (S[i] == "z" and S[i + 2] == "a"):
            S[i + 1] = "b"
        else:
            m = S[i]
            if m < S[i + 2]:
                m = S[i + 2]
            S[i + 1] = increment_char(m)
    if S[-1] == S[-2]:
        S[-1] = increment_char(S[-1])
    return "".join(S)


def main():
    s = input()
    print(solve(s))


if __name__ == "__main__":
    main()
