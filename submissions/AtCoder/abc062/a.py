a = [1, 3, 5, 7, 8, 10, 12]
b = [4, 6, 9, 11]
c = [2]

x, y = map(int, input().split())
print(['No', 'Yes'][any(x in g and y in g for g in [a, b, c])])
