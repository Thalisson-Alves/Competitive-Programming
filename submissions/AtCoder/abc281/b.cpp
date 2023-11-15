import re
print(['No', 'Yes'][bool(re.fullmatch(r'[A-Z][1-9][0-9]{5}[A-Z]', input()))])
