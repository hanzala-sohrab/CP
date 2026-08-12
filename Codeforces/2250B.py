def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        if n == 2:
            print("01" if k == 0 else -1)
            continue
        if k == n - 1:
            print(0 if n == 1 else -1)
            continue
        
        s = ""
        c0 = (n + 1) // 2
        c1 = n // 2
        k = n - k
        for i in range(1, k + 1):
            if i % 2 == 1:
                if i >= k - 1:
                    while c0 > 0:
                        s += "0"
                        c0 -= 1
                else:
                    s += "0"
                    c0 -= 1
            else:
                if i >= k - 1:
                    while c1 > 0:
                        s += "1"
                        c1 -= 1
                else:
                    s += "1"
                    c1 -= 1
        print(s)

        
if __name__ == "__main__":
	main()
