import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N = int(input())
district = []
visited = [[False] * N for _ in range(N)]
answers = []
max_height = 0

def is_in(x, y):
    return x >= 0 and x < N and y >= 0 and y < N

def dfs(x, y, rain_h):
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    for d in directions:
        new_x = x + d[0]
        new_y = y + d[1]

        if is_in(new_x, new_y) and not visited[new_x][new_y] and district[new_x][new_y] >= rain_h:
            visited[new_x][new_y] = True
            dfs(new_x, new_y, rain_h)

for _ in range(N):
    inputs = [int(n) for n in input().split()]
    district.append(inputs)
    max_height = max(max_height, max(inputs))

for height in range(max_height + 1):
    visited = [[False] * N for _ in range(N)]
    answer = 0

    for x in range(N):
        for y in range(N):
            if district[x][y] >= height and not visited[x][y]:
                visited[x][y] = True
                dfs(x, y, height)
                answer += 1

    answers.append(answer)

print(max(answers))