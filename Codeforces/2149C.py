from typing import List

def find(a: List[int], n: int, k: int) -> int:
    sorted(a)
    ans = 0
    m = 0
    freq = [0] * (n + 1)
    for el in a:
        freq[el] += 1
    for i in range(k):
        if freq[i] == 0:
            if freq[k] > 0:
                freq[k] -= 1
            freq[i] += 1
            ans += 1
    if freq[k] > 0:
        ans += freq[k]
        freq[k] = 0
    return ans


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        ans = find(a, n, k)
        print(ans)
