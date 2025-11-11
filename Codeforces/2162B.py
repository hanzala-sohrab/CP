def find(s: str):
    n = len(s)
    p_arr = [i + 1 for i in range(n) if s[i] == '1']
    if len(p_arr) == 0:
        print(0)
        print()
        return

    print(len(p_arr))
    print(*p_arr)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        find(s)
