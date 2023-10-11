#!/usr/bin/python3

def solve():
    x, y = input().split()
    for i in range(2, 37):
        for j in range(2, 37):
            try:
                if int(x, i) == int(y, j):
                    return f'{x} (base {i}) = {y} (base {j})'
            except:
                ...
    return f'{x} is not equal to {y} in any base 2..36'

try:
    while True:
        print(solve())
except:
    ...

