from math import pi, sin

while True:
    try:
        r, n = map(float, input().split())
    except:
        break
    a = 2 * pi / n
    print(f'{(sin(a) * r * r / 2) * n:.3f}')
