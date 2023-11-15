def solve():
    a = int(input())
    print(a + (2 - a % 4) % 4)


if __name__ == '__main__':
    solve()
