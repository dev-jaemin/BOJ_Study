from collections import defaultdict
from collections import deque

# inputs

N = int(input())
K = int(input())
apple = [[False] * (N + 1) for _ in range(N + 1)]

for _ in range(K):
    a, b = [int(n) for n in input().split()]
    apple[a][b] = True

L = int(input())
moves = defaultdict(str)

for _ in range(L):
    t, d = input().split()
    moves[int(t)] = d

# logic
snake_deque = deque([(1, 1)])

def is_on_board(pos):
    if pos[0] < 1 or pos[0] > N:
        return False
    
    if pos[1] < 1 or pos[1] > N:
        return False
    
    return True

def move(direction):
    next = (0, 1)

    if direction == 1:
        next = (1, 0)
    elif direction == 2:
        next = (0, -1)
    elif direction == 3:
        next = (-1, 0)
    
    head_next = (snake_deque[0][0] + next[0], snake_deque[0][1] + next[1])

    if not is_on_board(head_next):
        return False
    
    if head_next in snake_deque:
        return False
        
    if not apple[head_next[0]][head_next[1]]:
        snake_deque.pop()
    else:
        apple[head_next[0]][head_next[1]] = False

    snake_deque.appendleft(head_next)
    return True

t = 0
direction = 0

while True:
    t += 1
    is_move_success = move(direction)

    if not is_move_success:
        break

    if moves[t]:
        direction = (direction + 1 if moves[t] == 'D' else direction - 1) % 4

print(t)