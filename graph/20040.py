import sys

sys.setrecursionlimit(10 ** 6)

N, M = [int(n) for n in sys.stdin.readline().split()]
parents = [n for n in range(N)]
rank = [1 for _ in range(N)]


def find_root(n):
    if parents[n] != n:
        return find_root(parents[n])

    return n


def union_parent(a, b):
    root_a = find_root(a)
    root_b = find_root(b)

    if rank[a] < rank[b]:
        parents[root_a] = root_b
        rank[root_b] += rank[root_a]
    else:
        parents[root_b] = root_a
        rank[root_a] += rank[root_b]


def has_same_root(a, b):
    return find_root(a) == find_root(b)


is_found = False

for count in range(M):
    a, b = [int(n) for n in sys.stdin.readline().split()]
    if has_same_root(a, b):
        print(count + 1)
        is_found = True
        break

    union_parent(a, b)

if not is_found:
    print(0)
