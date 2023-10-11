a, b, c = map(int, input().split())
print('delicious' if b-c>=0 else 'safe' if c-b<=a else 'dangerous')
