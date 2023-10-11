while True:
    try:
        j, r = map(int, input().split())
        ans = 0, 0
        d = {}
        for i, x in enumerate(list(map(int, input().split()))):
            d[i%j] = d.get(i%j, 0) + x
            if d[i%j] >= ans[0]:
                ans = d[i%j], i%j
        print(ans[1]+1)
    except:break

