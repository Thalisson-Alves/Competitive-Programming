#!/usr/bin/python3

from string import ascii_uppercase


def convert(x, b):
    nums = ''.join(map(str, range(10))) + ascii_uppercase
    ans = ''
    while x:
        x, r = divmod(x, b)
        ans += nums[r]

    if not ans:
        ans = '0'
    return ans[::-1]


def solve():
    a, b, c = input().split()
    a, b = map(int, (a, b))
    try:
        ans = convert(int(c, a), b)
        return f'{c} base {a} = {ans} base {b}'
    except:
        return f'{c} is an illegal base {a} number'

try:
    while True:
        print(solve())
except Exception as e:
    ...

