import sys

sys.setrecursionlimit(10**6+100)

INF = 987654321
N = int(sys.stdin.readline())
adjacent = [set() for _ in range(N + 1)]
visited = [False] * (N + 1)
dp = [[INF, INF] for _ in range(N + 1)]

for _ in range(N - 1):
    u, v = [int(n) for n in sys.stdin.readline().split()]
    adjacent[u].add(v)
    adjacent[v].add(u)

def get_min(root, is_root_early):
    if dp[root][is_root_early] < INF:
        return dp[root][is_root_early]

    # root가 false이면 subtree는 모두 true여야 하고, root가 true면 subtree는 상관없음

    ret = 0
    if is_root_early:
        ret = 1

        for subtree in adjacent[root]:
            if visited[subtree]:
                continue
            
            visited[subtree] = True
            ret += min(get_min(subtree, True), get_min(subtree, False) if get_min(subtree, False) < INF else 0)
    else:
        for subtree in adjacent[root]:
            if visited[subtree]:
                continue

            ret += get_min(subtree, True)
        
        if ret == 0:
            visited[root] = False
            return INF
    
    dp[root][is_root_early] = ret
    visited[root] = False
    return ret

visited[1] = True
print(min(get_min(1, True), get_min(1, False)))