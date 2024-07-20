import sys

sys.setrecursionlimit(10 ** 6)

N = int(sys.stdin.readline())
solutions = sys.stdin.readline().split()
solutions = [int(n) for n in solutions]

left_index = 0
right_index = len(solutions) - 1
answer = {'left_index': left_index, 'right_index': right_index, 'min_value': 2000000000} 

while left_index < right_index:
    mixed_solution_value = solutions[left_index] + solutions[right_index]

    if abs(mixed_solution_value) <= answer['min_value']:
        answer['left_index'] = left_index
        answer['right_index'] = right_index
        answer['min_value'] = abs(mixed_solution_value)
    
    if mixed_solution_value >= 0:
        right_index = right_index - 1
    else:
        left_index = left_index + 1
    
print(solutions[answer['left_index']], solutions[answer['right_index']])
