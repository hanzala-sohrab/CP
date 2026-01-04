def solve(s: str, t: str) -> str:
    freq_s = [0] * 26
    freq_t = [0] * 26
    for ch in s:
        ind = ord(ch) - ord("a")
        freq_s[ind] += 1
    for ch in t:
        ind = ord(ch) - ord("a")
        freq_t[ind] += 1

    for i in range(26):
        if freq_t[i] < freq_s[i]:
            return "Impossible"

    res = ""
    for ch in s:
        ind = ord(ch) - ord("a")
        for i in range(ind + 1):
            while freq_t[i] > freq_s[i] and ch != chr(i + ord("a")):
                res += chr(i + ord("a"))
                freq_t[i] -= 1
        res += ch
        freq_t[ind] -= 1
        freq_s[ind] -= 1

    for i in range(26):
        while freq_t[i] > 0:
            res += chr(i + ord("a"))
            freq_t[i] -= 1

    return res


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        s = input()
        t = input()
        print(solve(s, t))
