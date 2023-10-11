def solve():
    input()
    a, b, c = [set(input().split()) for _ in range(3)]
    ap = bp  = cp = 0
    for s in a:
        p = 3
        if s in b:
            p = 1
        if s in c:
            p = 0 if p == 1 else 1
        ap += p
    for s in b:
        p = 3
        if s in a:
            p = 1
        if s in c:
            p = 0 if p == 1 else 1
        bp += p
    for s in c:
        p = 3
        if s in b:
            p = 1
        if s in a:
            p = 0 if p == 1 else 1
        cp += p
    print(ap, bp, cp)

if __name__ == '__main__':
    for _ in range(int(input())):
        solve()

