_=input()
l = [*map(int, input().split())]
d = {}
for i in range(len(l)-1,-1,-1):
    try:
        t = max((k,v) for k,v in d.items() if k < l[i])
        x = t[1]
        l[i],l[x] = l[x],l[i]
        break
    except:
        d[l[i]] = i

ans = l[:i+1] + sorted(l[i+1:], reverse=True)
print(*ans)