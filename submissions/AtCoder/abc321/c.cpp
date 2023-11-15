num = set()
for i in range(1, 10):
    ds = [x for x in range(i, -1, -1)]
    for j in range(1, 1 << len(ds)):
        n = ''
        for k in range(0, len(ds)):
            if (1 << k) & j:
                n += str(ds[k])
        num.add(int(n))

print(sorted(num)[int(input())])
