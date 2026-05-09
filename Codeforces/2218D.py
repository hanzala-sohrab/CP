import math

def generate_n_primes(n):
    if n <= 0:
        return []

    # Small cases
    if n == 1:
        return [2]

    # Estimate upper bound for nth prime
    limit = int(n * (math.log(n) + math.log(math.log(n)))) + 10

    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(math.sqrt(limit)) + 1):
        if sieve[i]:
            for j in range(i * i, limit + 1, i):
                sieve[j] = False

    primes = []

    for i in range(2, limit + 1):
        if sieve[i]:
            primes.append(i)

            if len(primes) == n:
                break

    return primes

def main():
    M = int(1e18)
    primes = generate_n_primes(int(1e4))

    for _ in range(int(input())):
        n = int(input())
        num = 1
        a = [1]
        for i in range(n - 1):
            a.append(primes[i] * primes[i + 1])

        print(*a)


if __name__ == "__main__":
    main()
