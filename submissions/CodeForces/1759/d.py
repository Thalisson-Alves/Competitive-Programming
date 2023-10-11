import math
for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = 0
    i = 10
    c = math.lcm(n, i)
    while c // n <= m:
        ans = c
        i *= 10
        c = math.lcm(n, i)

    if not ans:
        print(n * m)
    else:
        rest = m // (ans // n)
        print(rest * ans)

