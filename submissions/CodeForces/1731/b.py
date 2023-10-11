MOD = int(1e9+7)

def S2(n): return (n * (n + 1) * (2 * n + 1) // 6) % MOD
def S1(n): return (n * (n-1) // 2) % MOD

for _ in range(int(input())):
    n = int(input())
    ans = S2(n) + S2(n-1) + S1(n)
    print((2022 * ans) % MOD)

