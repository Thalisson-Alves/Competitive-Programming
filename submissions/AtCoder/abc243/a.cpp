v, *l = map(int, input().split())
ss = 'FMT'
v %= sum(l)
for a, b in zip(l, ss):
    v -= a
    if v < 0:
        print(b)
        break
