if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        if "**" in s or "*<" in s or ">*" in s or "><" in s:
            print(-1)
            continue
        n = len(s)
        if n == 1:
            print(1)
            continue
        if s[0] == ">" or s[n - 1] == "<":
            print(n)
            continue
        c1 = s.count("<")
        c2 = s.count(">")
        c3 = s.count("*")
        print(max(c1, c2) + c3)
