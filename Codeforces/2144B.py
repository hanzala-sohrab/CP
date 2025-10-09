from typing import List

def cost(n: int, p: List[int]) -> int:
    s = set(p)
    i = n
    missing_elements = []
    while i > 0:
        if i not in s:
            missing_elements.append(i)
        i -= 1
    i = 0
    for j in range(n):
        if p[j] == 0:
            p[j] = missing_elements[i]
            i += 1
    q = [el for el in p]
    q.sort()

    i = 0
    while i < n:
        if p[i] != q[i]:
            break
        i += 1

    j = n - 1
    while j >= 0:
        if p[j] != q[j]:
            break
        j -= 1
    
    return j - i + 1 if j > i else 0


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        print(cost(n, p))
