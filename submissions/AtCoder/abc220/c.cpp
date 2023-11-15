n = int(input())
v = [*map(int, input().split())]
k = int(input())

pref = [0] * (n+1)
for i in range(n):
    pref[i+1] = pref[i] + v[i]

def ssum(x):
    ans = pref[-1] * (x // n)
    return ans + pref[x%n]

l = 0
r = k
while l <= r:
    mid = (r + l) // 2
    ans = ssum(mid)
    if ans > k:
        r = mid - 1
    else:
        l = mid + 1


print(l)

