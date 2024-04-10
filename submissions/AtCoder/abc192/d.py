x = [*map(int, input().strip())][::-1]
m = int(input())


def can(base):
    res = 0
    power = 1
    for c in x:
        res += c * power
        if res > m or power > m:
            return False
        power *= base
    return True


if len(x) == 1:
    print(int(x[0] <= m))
    exit(0)

d = max(x)
l = d + 1
r = m + 10
while l <= r:
    mid = l + (r - l) // 2
    if can(mid):
        l = mid + 1
    else:
        r = mid - 1

print(r - d)
