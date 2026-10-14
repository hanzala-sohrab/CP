import sys

input = sys.stdin.readline


def main():
    limit = 10**6
    snowflakes = set()

    for k in range(2, 1001):
        total = 1 + k
        power = k * k

        while total + power <= limit:
            total += power
            snowflakes.add(total)
            power *= k

    t = int(input())

    for _ in range(t):
        n = int(input())
        print("YES" if n in snowflakes else "NO")


if __name__ == "__main__":
    main()
