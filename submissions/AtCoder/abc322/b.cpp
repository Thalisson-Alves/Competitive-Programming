#!/usr/bin/python3

n, m = map(int, input().split())
s = input()
t = input()
if t.startswith(s) and t.endswith(s):
    print(0)
elif t.startswith(s):
    print(1)
elif t.endswith(s):
    print(2)
else:
    print(3)
