import sys

N = int(sys.stdin.readline().split()[0])
solutions = [int(n) for n in sys.stdin.readline().split()]
solutions.sort()
min_value = 10 ** 13
answers = [solutions[0], solutions[1] , solutions[2]]

for start in range(N - 1):
    left_pointer = start + 1
    right_pointer = N - 1

    while left_pointer < right_pointer:
        sum = solutions[start] + solutions[left_pointer] + solutions[right_pointer]

        if abs(sum) < min_value:
            answers = [solutions[start], solutions[left_pointer], solutions[right_pointer]]
            min_value = abs(sum)
        
        if sum < 0:
            left_pointer += 1
        else:
            right_pointer -= 1

print(" ".join([str(n) for n in answers]))