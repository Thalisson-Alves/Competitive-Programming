b = int(input())
for a in range(1, b+1):
    p = pow(a, a)
    if p == b:
        print(a)
        break
    if p > b:
        print(-1)
        break
