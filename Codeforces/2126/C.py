def is_possible(n: int, k: int, h: list[int]) -> bool:
    current_height = h[k - 1]
    h.sort()
    water_level = 0
    for i in range(n):
        if h[i] <= current_height:
            continue

        water_level += h[i] - current_height

        if water_level >= current_height:
            return False

        current_height = h[i]

    return True


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        h = list(map(int, input().split()))
        print("yes" if is_possible(n, k, h) else "no")
