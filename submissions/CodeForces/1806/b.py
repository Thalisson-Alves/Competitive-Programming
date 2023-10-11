#!/usr/bin/python3

for _ in range(int(input())):
    n = int(input())
    l = [*map(int, input().split())]
    zeros = l.count(0)
    if zeros <= (n+1) // 2:
        print(0)
        continue

    if max(l) == 1:
        print(2)
    else:
        print(1)

