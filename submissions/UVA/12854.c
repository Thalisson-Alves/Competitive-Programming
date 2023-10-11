while True:
    try:
        print('YN'[any(x==y for x,y in zip(input().split(),input().split()))])
    except:break

