def arboris_contractio():
    t = int(input())
    for _ in range(t):
        n = int(input())
        g = [[] for _ in range(n)]
        degree = [0] * n

        for _ in range(n - 1):
            u, v = map(int, input().split())
            u -= 1
            v -= 1

            g[u].append(v)
            g[v].append(u)

            degree[u] += 1
            degree[v] += 1

        if n <= 3:
            print(0)
            continue

        total_leaf_count = sum(1 for u in range(n) if degree[u] == 1)
        max_adjacent_leaf_count = max(
            sum(1 for v in g[u] if degree[v] == 1) for u in range(n)
        )

        answer = total_leaf_count - max_adjacent_leaf_count

        print(answer)


if __name__ == "__main__":
    arboris_contractio()
