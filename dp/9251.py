import sys
from functools import lru_cache
sys.setrecursionlimit(10 ** 6)

str1 = sys.stdin.readline()[:-1]
str2 = sys.stdin.readline()[:-1]

@lru_cache(maxsize=10 ** 6)
def lcs(a, b):
    if a == 0 and b == 0:
        return 1 if str1[a] == str2[b] else 0
    
    if a < 0 or b < 0:
        return 0

    if str1[a] == str2[b]:
        return lcs(a - 1, b - 1) + 1
    else:
        return max(lcs(a - 1, b), lcs(a, b - 1))
    
print(lcs(len(str1) - 1, len(str2) - 1))