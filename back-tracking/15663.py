import sys
from itertools import permutations

sys.setrecursionlimit(10 ** 6)

N, M = sys.stdin.readline().split()
input_numbers = sys.stdin.readline().split()

N = int(N)
M = int(M)
input_numbers = [int(n) for n in input_numbers]
answer_set = set()

for cwr in permutations(input_numbers, M):
    answer_set.add(cwr)

sorted_answer_list = sorted(list(answer_set))

for answer in sorted_answer_list:
    answer_to_string = [str(n) for n in answer]
    output_sequence = " ".join(answer_to_string)
    print(output_sequence)