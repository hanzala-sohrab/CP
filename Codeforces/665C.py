def solve(s: str) -> str:
    S = list(s)
    n = len(S)

    for i in range(1, n):
        if S[i] == S[i - 1]:
            for c in "abcdefghijklmnopqrstuvwxyz":
                if c != S[i - 1] and (i + 1 == n or c != S[i + 1]):
                    S[i] = c
                    break

    return "".join(S)


def main():
    s = input()
    print(solve(s))


if __name__ == "__main__":
    main()
