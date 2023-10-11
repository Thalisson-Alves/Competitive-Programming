t = int(input())
for i in range(t):
    l = sorted(map(int, input().split()))
    if l[0] == l[1]:
        print('YES' if l[2] % 2 == 0 else 'NO')
    elif l[1] == l[2]:
        print('YES' if l[0] % 2 == 0 else 'NO')
    else:
        print('YES' if l[2] - l[0] == l[1] else 'NO')
