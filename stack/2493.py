import sys

N = int(sys.stdin.readline())
# 맨 앞에 높이 0짜리 건물 추가
heights = [0]
heights = heights + [int(h) for h in sys.stdin.readline().split()]
receives = [0 for _ in range(N + 1)]
stack = [0]

for i in range(1, N + 1):
    if heights[i - 1] > heights[i]:
        receives[i] = i - 1
        stack.append(i)
        continue

    top = stack.pop()
    while len(stack) > 0:
        if heights[top] < heights[i]:
            top = stack.pop()
            continue
        else:
            break
    
    if heights[top] < heights[i]:
        # i보다 큰 탑이 왼쪽에 없다.
        receives[i] = 0
        stack.append(i)
    else:
        # i보다 큰 탑이 top 위치에 있다.
        receives[i] = top
        stack.append(top)
        stack.append(i)

print(' '.join([str(n) for n in receives[1: ]]))