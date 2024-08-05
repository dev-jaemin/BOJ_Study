import sys
from collections import deque

sys.setrecursionlimit(10 ** 6)
T = int(sys.stdin.readline())

for _ in range(T):
    # 건물의 수와 규칙의 수
    N, K = [int(n) for n in sys.stdin.readline().split()]
    adjacent_list = [set() for _ in range(N + 1)]
    build_times = [0] + [int(n) for n in sys.stdin.readline().split()]
    num_parents = [0] * (N + 1)
    time_consumed = [0] * (N + 1)

    for _ in range(K):
        a, b = [int(n) for n in sys.stdin.readline().split()]
        adjacent_list[a].add(b)
        num_parents[b] += 1
    
    # 최종 목표 건물
    last = int(sys.stdin.readline())
    
    q = deque([])
    starters = [i for i in range(1, N + 1) if num_parents[i] == 0]
    q.extend(starters)
    for s in starters:
        time_consumed[s] = build_times[s]

    while q:
        front = q.popleft()

        for adjacent in adjacent_list[front]:
            time_consumed[adjacent] = max(time_consumed[adjacent], time_consumed[front] + build_times[adjacent])
            num_parents[adjacent] -= 1

            if num_parents[adjacent] == 0:
                q.append(adjacent)

    print(time_consumed[last])
