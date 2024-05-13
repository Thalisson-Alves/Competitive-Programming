a, b, k = map(int, input().split())


def comb(x, y):
    if y < x:
        x, y = y, x

    tot = 1
    for i in range(y + 1, x + y + 1):
        tot *= i
    for i in range(2, x + 1):
        tot //= i
    return tot


s = ""
for i in range(a + b):
    if not a:
        s += "b"
        b -= 1
        continue
    elif not b:
        s += "a"
        a -= 1
        continue

    if comb(a - 1, b) >= k:
        s += "a"
        a -= 1
    else:
        s += "b"
        k -= comb(a - 1, b)
        b -= 1

print(s)
