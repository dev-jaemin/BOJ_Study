import sys
from collections import deque
from functools import lru_cache
sys.setrecursionlimit(10 ** 6)

N, R, Q = [int(n) for n in sys.stdin.readline().split()]
adjacent_matrix = [set() for _ in range(N + 1)]
subtree_count = [0] * (N + 1)
visitied = [False] * (N + 1)

def get_subtree_count(root):
    sum = 1

    for child in adjacent_matrix[root]:
        if not visitied[child]:
            visitied[child] = True
            sum += get_subtree_count(child)

    subtree_count[root] = sum
    return sum


# 입력 받고, 인접행렬 만들기
for i in range(N - 1):
    a, b = [int(n) for n in sys.stdin.readline().split()]
    adjacent_matrix[a].add(b)
    adjacent_matrix[b].add(a)

# 재귀 순환하면서 subtree의 노드 수 세기
visitied[R] = True
get_subtree_count(R)

# 쿼리를 입력 받고 대답
for _ in range(Q):
    q = int(sys.stdin.readline())
    print(subtree_count[q])
