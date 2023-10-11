import enum


_, *l = open(0)
for i, s in enumerate(l, 1):
    print(f'Case {i}: {sorted(map(int, s.split()))[1]}')