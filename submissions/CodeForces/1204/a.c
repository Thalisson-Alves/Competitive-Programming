x = int(input(), 2)
x = max(x-1, 0)
ans = 0
while x:
    x >>= 2
    ans+=1
print(ans)
