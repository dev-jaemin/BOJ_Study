import sys
import heapq

input = sys.stdin.readline

N = int(input())
heap = []

for n in [int(n) for n in input().split()]:
    heapq.heappush(heap, n)

for _ in range(1, N):
    for n in [int(n) for n in input().split()]:
        heapq.heappush(heap, n)
        heapq.heappop(heap)

print(heap[0]) 