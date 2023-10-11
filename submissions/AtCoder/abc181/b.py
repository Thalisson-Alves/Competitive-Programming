ans = 0
for i in range(int(input())):
    a, b = map(int, input().split())
    ans += (b + a) * (b - a + 1) // 2
print(ans)