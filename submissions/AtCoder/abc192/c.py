n, k = map(int, input().split())
for _ in range(k):
    ss = sorted(str(n))
    n = int("".join(ss[::-1])) - int("".join(ss))

print(n)
