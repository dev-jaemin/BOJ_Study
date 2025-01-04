import sys
from collections import Counter

word = sys.stdin.readline()[:-1]
counter = Counter(word.upper())

most_common = counter.most_common()

if len(most_common) == 1:
    print(most_common[0][0])
elif most_common[0][1] == most_common[1][1]:
    print('?')
else:
    print(most_common[0][0])