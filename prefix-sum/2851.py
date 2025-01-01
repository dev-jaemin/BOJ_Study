import sys

N = 10
psum = [0 for _ in range(N + 1)]
min = 999999
min_value = -1

for idx in range(1, N + 1):
    psum[idx] = psum[idx - 1] + int(sys.stdin.readline())

for idx in range(1, N + 1):
    if abs(100 - psum[idx]) <= min:
        min = abs(100 - psum[idx])
        min_value = psum[idx]

print(min_value)