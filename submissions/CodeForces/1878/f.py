#!/usr/bin/python3

from collections import defaultdict
from math import prod


def factors(n) -> dict[int, int]:
    ans = defaultdict(int)
    for i in range(2, int(n**.5)+1):
        c = 0
        while n % i == 0:
            c += 1
            n //= i
        if c:
            ans[i] = c
    if n > 1:
        ans[n] = 1

    return ans


for _ in range(int(input())):
    n, q = map(int, input().split())
    fs = factors(n)
    FS = fs.copy()
    cur_n = n

    for _ in range(q):
        t, *r = input().split()
        if t == '2':
            cur_n = n
            fs = FS.copy()
            continue

        r = int(r[0])
        cur_n *= r

        for k, v in factors(r).items():
            fs[k] += v

        if cur_n % prod(x+1 for x in fs.values()):
            print('NO')
        else:
            print('YES')
    print()
