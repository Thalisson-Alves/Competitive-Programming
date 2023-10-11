import math


def solve():
    n = int(input())
    names = sorted([input() for _ in range(n)])
    max_w = max(map(len, names))
    cols = 62 // (2 + max_w)
    rows = math.ceil(n / cols)
    mat = [names[i:i+rows] for i in range(0, n, rows)]
    transpose = [[''] * cols for _ in range(rows)]
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            transpose[j][i] = mat[i][j]

    print('-' * 60)
    for row in transpose:
        print(*[x.ljust(max_w) for x in row], sep='  ')


while True:
    try: solve()
    except: break

