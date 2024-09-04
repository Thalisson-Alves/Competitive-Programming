s = input()
a, b = [], []
for x in [a for e in [x.split(';') for x in s.split(',')] for a in e]:
    if x=='0' or (x and x[0] != '0' and x.isdigit()):
        a.append(x)
    else:
        b.append(x)

print(f'"{",".join(a)}"' if a else '-')
print(f'"{",".join(b)}"' if b else '-')
