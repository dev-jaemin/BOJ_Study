import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 5)
answers = defaultdict(int)

def make_cantor_set(N, sentence):
    if N == 0:
        return sentence
    
    if answers[str(N)]:
        return answers[str(N)]
    
    next_str_length = 3 ** (N - 1)
    white_str = ' ' * next_str_length

    return make_cantor_set(N - 1, sentence[:next_str_length]) + make_cantor_set(N - 1, white_str) + make_cantor_set(N - 1, sentence[2 * next_str_length:])

inputs = []

while True:
    try:
        line = input().strip()
        inputs.append(int(line))
    except EOFError:
        break

for N in inputs:
    print(make_cantor_set(N, '-' * (3 ** N)))