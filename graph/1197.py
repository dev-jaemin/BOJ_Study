import sys
sys.setrecursionlimit(10 ** 6)

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    if rootX != rootY:
        if rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        elif rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        else:
            parent[rootY] = rootX
            rank[rootX] += 1

input = sys.stdin.readline
data = input().split()
num_edges = int(data[0])
num_vertices = int(data[1])

edges = []
for _ in range(num_vertices):
    data = input().split()
    a = int(data[0])
    b = int(data[1])
    dist = int(data[2])
    edges.append((dist, a, b))

edges.sort()
parent = [i for i in range(num_edges + 1)]
rank = [0] * (num_edges + 1)

mst_weight = 0
selected_edges = 0

for dist, a, b in edges:
    if find(parent, a) != find(parent, b):
        union(parent, rank, a, b)
        mst_weight += dist
        selected_edges += 1

        if selected_edges == num_edges - 1:
            break

print(mst_weight)