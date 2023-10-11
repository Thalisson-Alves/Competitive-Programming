N = 1 << 64

ans = {1}

for p in [2, 3, 5, 7, 9]:
    i = 1
    while (i:=i+1)**(p*2) < N:
        j = i**(p*2)

        while j < N:
            ans.add(j)
            j *= i**p

for x in sorted(ans):
    print(x)

