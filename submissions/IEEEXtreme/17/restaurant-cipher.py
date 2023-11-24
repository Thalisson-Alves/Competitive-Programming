#!/usr/bin/python3

from collections import Counter

n = int(input())
lines = [input().lower() for _ in range(n)]

for line in lines:
    cypher = 'x'
    for a, b in Counter(line).most_common():
        if cypher == 'x' and a in 'abcdefg':
            cypher = a
            break
    print(cypher.upper())
