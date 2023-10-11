import re
import math
from collections import Counter

def entropy(words):
    freq = Counter(words)
    return sum(v*math.log(len(words) / v, 10) for v in freq.values()) / len(words)


def read_string():
    s = ''
    while True:
        i = input()
        if i == '****END_OF_TEXT****':
            break
        elif i == '****END_OF_INPUT****':
            return i
        s += ' ' + i
    return s


while True:
    s = read_string()
    if s == '****END_OF_INPUT****': break
    words = re.sub(r'[,.:;!?"()]', ' ', s.lower()).split()
    ent = entropy(words)
    print(f'{len(words)} {ent:.1f} {round(ent * 100 / math.log(len(words), 10))}')

