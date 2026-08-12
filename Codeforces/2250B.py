def main():
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())

        runs = n - k

        # All characters would have to be equal.
        # Counts would differ by n-0, which is > 1 for n >= 2.
        if runs == 1:
            print(-1)
            continue

        c0 = (n + 1) // 2
        c1 = n // 2

        ans = []

        # We want 'runs' alternating blocks.
        # Start with 0.
        for i in range(runs):
            if i % 2 == 0:
                ans.append('0')
                c0 -= 1
            else:
                ans.append('1')
                c1 -= 1

        # Distribute remaining characters.
        #
        # Add them to the last block.
        if (runs - 1) % 2 == 0:
            ans[-1] += '0' * c0
        else:
            ans[-1] += '1' * c1

        print(''.join(ans))


if __name__ == "__main__":
    main()
