import sys
from itertools import combinations_with_replacement

sys.setrecursionlimit(10 ** 6)

N, M = sys.stdin.readline().split()
N = int(N)
M = int(M)

for cwr in combinations_with_replacement(range(1, N + 1), M):
    print(" ".join(list(map(str, cwr))))