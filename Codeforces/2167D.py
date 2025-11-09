primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]

def solve(a):
    m = int(1e18)
    for p in primes:
        for n in a:
            if n % p != 0:
                m = min(m, p)
                break
    return m


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a))


