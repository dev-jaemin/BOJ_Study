import sys
from itertools import permutations

sys.setrecursionlimit(10 ** 6)

N, M = sys.stdin.readline().split()
N = int(N)
M = int(M)
numbers = [int(n) for n in sys.stdin.readline().split()]

numbers.sort()
answers_set = set()

for pmt in permutations(numbers, M):
    answers_set.add(pmt)

answer_list = sorted(list(answers_set))

for answer in answer_list:
    print(" ".join([str(n) for n in list(answer)]))