import sys
from collections import deque

N, M = [int(n) for n in sys.stdin.readline().split()]
tall_than = [set() for _ in range(N + 1)]
indegrees = [0] * (N + 1)

for _ in range(M):
    a, b = [int(n) for n in sys.stdin.readline().split()]
    tall_than[a].add(b)
    indegrees[b] += 1

q = deque([n for n in range(1, N + 1) if indegrees[n] == 0])
sorted_students = []

while len(q) > 0:
    front = q.popleft()
    sorted_students.append(front)

    for neighbor in tall_than[front]:
        indegrees[neighbor] -= 1

        if indegrees[neighbor] == 0:
            q.append(neighbor)

print(" ".join([str(n) for n in sorted_students]))