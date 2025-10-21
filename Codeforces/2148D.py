from typing import List


def solve(a: List[int]) -> int:
    a.sort(reverse=True)

    odd_elements = [el for el in a if el % 2 == 1]
    even_elements = [el for el in a if el % 2 == 0]

    L = len(odd_elements)

    if L == 0:
        return 0

    # two pointers
    i, j = 0, L - 1

    ans = sum(even_elements)

    while j >= i:
        ans += odd_elements[i]
        i += 1
        j -= 1

    return ans


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(a))
