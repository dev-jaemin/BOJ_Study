import sys
from queue import PriorityQueue
sys.setrecursionlimit(10 ** 5)
N, M = [int(n) for n in sys.stdin.readline().split()]
edges = PriorityQueue()
selected_edges = []
parents = [i for i in range(N + 1)]

def find_root(n):
    if parents[n] != n:
        parents[n] = find_root(parents[n])

    return parents[n]

def union_root(a, b):
    parent_a = find_root(a)
    parent_b = find_root(b)

    if parent_a < parent_b:
        parents[parent_a] = parent_b
    else:
        parents[parent_b] = parent_a

def has_same_parent(a, b):
    return find_root(a) == find_root(b)

for _ in range(M):
    a, b, cost = [int(n) for n in sys.stdin.readline().split()]
    edges.put((cost, a, b))

while len(selected_edges) < N - 1:
    candidate = edges.get()

    if has_same_parent(candidate[1], candidate[2]):
        continue

    union_root(candidate[1], candidate[2])
    selected_edges.append(candidate)

costs = [e[0] for e in selected_edges[:-1]]
print(sum(costs))