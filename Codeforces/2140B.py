def find_y(x: int) -> int:
    return 8 * x

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        x = int(input())
        y = find_y(x)
        print(y)

