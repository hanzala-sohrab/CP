def is_power_of_two(n: int) -> bool:
    return n > 0 and (n & (n - 1)) == 0

def find(a: int, b: int) -> int:
    A = a % 2
    B = b % 2
    if A == 0 and B == 1:
        return -1
    if A == 1:
        if B == 1:
            return max(a + b, a * b + 1)
        if b % 4 != 0:
            return -1

    ans = (a + b) if A == 0 else (2 * a + b // 2)

    c = b
    k = 2
    while c % 2 == 0:
        e = b // k
        d = max(k * a + b // k, e * a + b // e) if b % k == 0 else 1
        if d % 2 == 0:
            ans = max(ans, d)
        k *= 2
        c //= 2

    return ans

if __name__ == "__main__":
	t = int(input())
	for _ in range(t):
		a, b = map(int, input().split())
		print(int(find(a, b)))
