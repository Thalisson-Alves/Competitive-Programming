from math import log10, floor


lg = log10(2)
for _ in range(int(input())):
    n = int(input())

    x = -n * lg
    e = int(floor(x))
    print(f'2^-{n} = {10**(x-e):.3f}E{e}')
