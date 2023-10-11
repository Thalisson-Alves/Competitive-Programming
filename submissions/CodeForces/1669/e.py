def solve():
    s = {}
    f = {}
    mp = {}
    for _ in range(int(input())):
        a = input()
        mp[a] = mp.get(a, 0) + 1
        s[a[0]] = s.get(a[0], 0) + 1
        f[a[1]] = f.get(a[1], 0) + 1
    ans = 0
    for a, i in mp.items():
        ans += i * (s[a[0]] - i) + i * (f[a[1]] - i)
    print(ans // 2)


t = int(input())
for i in range(t):
    solve()