input()
l = sorted({*map(int, input().split())})
ans = 0
for x in l:
    if x == ans:
        ans += 1
    else:
        break
print(ans)
