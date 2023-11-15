a, b, c, x = map(int, input().split())
print(1.0 if x <= a else c / (b-a) if x <= b else 0)
