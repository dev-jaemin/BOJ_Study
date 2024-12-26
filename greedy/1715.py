import sys
from queue import PriorityQueue

N = int(sys.stdin.readline())
answer = 0
pq = PriorityQueue()

for _ in range(N):
    pq.put(int(sys.stdin.readline()))

while pq.qsize() > 1:
    a = pq.get()
    b = pq.get()

    answer += a + b
    pq.put(a + b)

print(answer)