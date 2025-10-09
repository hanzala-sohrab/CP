from typing import List, Set

def is_possible(n: int, m: int, sets: List[Set[int]]) -> bool:
    freq = [0] * (m + 1)
    for s in sets:
        for el in s:
            freq[el] += 1

    for i in range(1, m + 1):
        if freq[i] == 0:
            return False

    union_set = set.union(*sets)

    cnt = 1

    for s in sets:
        flag = True
        for el in s:
            freq[el] -= 1
            if freq[el] == 0:
                flag = False
        
        if flag:
            cnt += 1

        for el in s:
            freq[el] += 1

    return cnt >= 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        sets: List[Set[int]] = []
        for i in range(n):
            inp = list(map(int, input().split()))
            l = inp[0]
            s = set(inp[1:])
            sets.append(s)
        print("yes" if is_possible(n, m, sets) else "no")

