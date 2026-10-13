import sys

input = sys.stdin.readline


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        c = sorted([(a[i] - b[i], i + 1) for i in range(n)], reverse=True)
        d = c[0][0]
        strong_vertices = [c[0][1]]
        for i in range(1, n):
            if c[i][0] != c[0][0]:
                break
            strong_vertices.append(c[i][1])
        print(len(strong_vertices))
        print(*sorted(strong_vertices))


if __name__ == "__main__":
    main()
