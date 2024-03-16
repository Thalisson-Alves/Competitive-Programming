s = input()
print(["No", "Yes"][len(s) >= 2 and s == f'<{"=" * (len(s) - 2)}>'])
