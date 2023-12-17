N, X, M = map(int, input().split())

vis = {X}
a = [X]

nxt = X
while len(a) <= N:
    nxt = (a[-1] * a[-1]) % M
    if nxt in vis:
        break
    a.append(nxt)
    vis.add(nxt)


if len(a) >= N:
    print(sum(a[:N]))
    exit()

cycle_start = a.index(nxt)
res = sum(a[:cycle_start])
cycle = sum(a[cycle_start:])

d, r = divmod(N - cycle_start, len(a) - cycle_start)
res += cycle * d + sum(a[cycle_start:cycle_start + r])
print(res)
