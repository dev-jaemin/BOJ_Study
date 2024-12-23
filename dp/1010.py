import sys
from math import comb

sys.setrecursionlimit(10 ** 5)

T = int(input())

for _ in range(T):
    N, M = [int(n) for n in sys.stdin.readline().split()]
    
    print(comb(M, N))