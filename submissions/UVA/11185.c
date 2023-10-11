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
    x = int(input())
    if x < 0:
        raise
    return convert(x, 3)

try:
    while True:
        print(solve())
except Exception as e:
    ...

