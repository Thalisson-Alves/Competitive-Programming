def sum_range(a, b):
    return (a + b) * (a + b - 1) // 2


n = int(input())
ans = 0
prev = 1
i = 10
while 1:
    if n >= i:
        ans += sum_range(1, i - prev)
    else:
        ans += sum_range(1, n - prev + 1)
        break
    prev = i
    i *= 10
print(ans % 998244353)
