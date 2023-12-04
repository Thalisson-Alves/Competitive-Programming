for _ in range(int(input())):
    n = input()
    s = input()
    l = [len(x) for x in s.split('#')]
    mx = max(l)
    if mx > 2:
        print(2)
    else:
        print(sum(x for x in l))
