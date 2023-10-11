from math import factorial

MOD = 998244353

n = int(input())
l = [*map(int, input().split())]
ans = 1
for i in range(n//3, n//6, -1):
    ans = ans * i
ans = (ans // factorial(n//6)) % MOD
for i in range(0, n, 3):
    x = l[i:i+3]
    ans = (ans * x.count(min(x))) % MOD
print(ans)

