n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = sum(x == y for x, y in zip(a, b))
print(ans)
print(len(set(a) & set(b)) - ans)