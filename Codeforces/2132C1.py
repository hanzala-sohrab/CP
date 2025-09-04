import math

def min_cost() -> int:
    n = int(input())
    cost = 0
    ind = 0
    while n > 0:
        rem = n % 3
        cost += rem * (3 ** (ind + 1) + ind * 3 ** (ind - 1))
        n //= 3
        ind += 1

    return int(cost)


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        print(min_cost())

