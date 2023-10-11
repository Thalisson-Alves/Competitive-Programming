input()
ls = list(map(int, input().split()))
m = e = c = 0
for x in ls:
    m += abs(x)
    c = max(c, abs(x))
    e += x**2
print(m)
print(e**.5)
print(c)
