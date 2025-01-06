import sys
import heapq

input = sys.stdin.readline

N = int(input())
class_heap = []
room_heap = []

for idx in range(N):
    s, t = [int(n) for n in input().split()]
    heapq.heappush(class_heap, (s, idx, { 's': s, 't': t }))

_, _, current = heapq.heappop(class_heap)
heapq.heappush(room_heap, (current['t'], 1, current))

for idx in range(N - 1):
    _, _, current = heapq.heappop(class_heap)
    _, _, earlist_room = room_heap[0]

    # 가장 빨리 끝났던 교실보다 current 시작이 더 뒤인 경우
    if earlist_room['t'] <= current['s']:
        heapq.heappop(room_heap)

    heapq.heappush(room_heap, (current['t'], idx, current))

print(len(room_heap))