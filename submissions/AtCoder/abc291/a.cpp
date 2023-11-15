s = input()
ans = 0
for i in range(len(s)):
    if s[i].isupper():
        ans = i + 1
        break
print(ans)
