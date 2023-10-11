def flip(idx):
    global l
    idx = len(l) - idx
    for i in range((idx + 1) // 2):
        l[i], l[idx-i] = l[idx-i], l[i]

for line in open(0):
    l = list(map(int, line.split()))
    print(*l)
    ans = []
    for i in range(len(l)):
        mx = max(range(len(l)-i), key=l.__getitem__)
        if mx == len(l)-1-i: continue
        if mx:
            ans.append(len(l)-mx)
            flip(ans[-1])
        ans.append(i+1)
        flip(ans[-1])
    print(*ans, 0)

