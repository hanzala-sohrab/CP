def main():
    for _ in range(int(input())):
        k = int(input())
        a1, b1 = map(int, input().split())
        a2, b2 = map(int, input().split())

        b3_max = min(k, 3 * k - (b1 + b2))

        b_total = b1 + b2 + b3_max
        a_total = a1 + a2

        if b_total > a_total:
            print('yes')
        else:
            print('no') 


if __name__ == "__main__":
    main()
