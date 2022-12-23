t = int(input())
for _ in range(t):
    n = int(input())
    s = input() + '#'
    ans = False
    for i in range(n):
        x = s.find(s[i:i+2])
        y = s.rfind(s[i:i+2])
        # print(f'x = {x}, y = {y}')
        if abs(x - y) > 1:
            ans = True
            break
    print("YES" if ans else "NO")
