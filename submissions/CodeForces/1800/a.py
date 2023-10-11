import re

for _ in range(int(input())):
    input()
    s = input().lower()
    if re.fullmatch(r'm+e+o+w+', s):
        print('YES')
    else:
        print('NO')
