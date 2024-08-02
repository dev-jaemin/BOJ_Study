import sys
sys.setrecursionlimit(10 ** 7)

N = int(sys.stdin.readline())
input_numbers = [int(n) for n in sys.stdin.readline().split()]
M = int(sys.stdin.readline())

is_palindrome = [[False] * N for _ in range(N)]

for i in range(N):
    is_palindrome[i][i] = True

for i in range(N - 1):
    is_palindrome[i][i + 1] = True if input_numbers[i] == input_numbers[i + 1] else False

for length in range(3, N + 1):
    for left in range(0, N - length + 1):
        right = left + length - 1
        is_palindrome[left][right] = input_numbers[left] == input_numbers[right] and is_palindrome[left + 1][right - 1]

for _ in range(M):
    question = [int(n) for n in sys.stdin.readline().split()]
    print(1 if is_palindrome[question[0] - 1][question[1] - 1] else 0)

