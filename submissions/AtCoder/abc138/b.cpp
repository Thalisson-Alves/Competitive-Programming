input()
l = [*map(int, input().split())]
print(f'{1/sum(1/x for x in l):.6f}')
