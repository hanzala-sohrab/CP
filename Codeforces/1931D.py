from collections import defaultdict
def main():
    t = int(input())
    for _ in range(t):
        n, x, y = map(int, input().split())
        a = list(map(int, input().split()))
        cnt = defaultdict(int)
        ans = 0
        for el in a:
            rem_y = el % y
            rem_x = el % x
            need = (x - rem_x) % x
            ans += cnt[(rem_y, need)]
            cnt[(rem_y, rem_x)] += 1
        print(ans)

if __name__ == "__main__":
    main()
