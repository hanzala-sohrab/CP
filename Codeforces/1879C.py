def main():
    M = 998244353
    t = int(input())
    for _ in range(t):
        s = input()
        n = len(s)
        min_ops = 0
        num = 1
        cnt = 1
        for i in range(1, n):
            if s[i] == s[i - 1]:
                cnt += 1
            else:
                min_ops += cnt - 1
                num = (num * cnt) % M
                cnt = 1
        min_ops += cnt - 1
        num = (num * cnt) % M
        fact = 1
        for j in range(2, min_ops + 1):
            fact = (fact * j) % M
        num = (num * fact) % M
        print(min_ops, num)


if __name__ == "__main__":
    main()
