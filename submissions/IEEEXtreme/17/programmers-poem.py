#!/usr/bin/python3

n, m = map(int, input().split())
groups = [[set(map(str.lower, input().split())), 'X'] for _ in range(n)]
input()
lines = [input().split()[-1].lower() for _ in range(m)]

cur_value = 'A'

ans = ['X'] * m
for i in range(m):
    if ans[i] != 'X':
        continue

    for k in range(i+1, m):
        for j in range(n):
            g, v = groups[j]
            if lines[i] in g and lines[k] in g:
                if ans[k] != 'X':
                    ans[i] = ans[k]
                elif v != 'X':
                    ans[i] = ans[k] = v
                else:
                    groups[j][1] = ans[i] = ans[k] = cur_value
                    cur_value = chr(ord(cur_value)+1)
                    if cur_value == 'X':
                        cur_value = chr(ord(cur_value)+1)
                break
print(*ans, sep='')
