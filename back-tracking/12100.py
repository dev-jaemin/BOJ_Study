import sys
from copy import deepcopy

sys.setrecursionlimit(10 ** 5)
N = int(sys.stdin.readline())
board_input = []
best = 0

for idx in range(N):
    board_input.append([int(n) for n in sys.stdin.readline().split()])

def moveLeft(board):
    moved_board = deepcopy(board)

    y_range = list(range(N))

    for x in range(N):
        new_line = []
        previous = 0

        # stack 삽입
        for y in y_range:
            # 0 만날 경우
            if moved_board[x][y] == 0:
                continue

            # 처음으로 만나는 숫자
            if previous == 0:
                previous = moved_board[x][y]
                continue

            # 이전 숫자와 같은 경우
            if moved_board[x][y] == previous:
                new_line.append(previous * 2)
                previous = 0
                continue

            # 이전 숫자와 다른 경우
            new_line.append(previous)
            previous = moved_board[x][y]

        new_line.append(previous)
        padded_line = padding(new_line, N)
        moved_board[x] = padded_line

    return moved_board

def find_current_max(board):
    flatten_board = sum(board, [])
    return max(flatten_board)

def padding(arr, n):
    ret = arr

    while len(ret) < n:
        ret.append(0)

    return ret

def transpose_matrix(matrix):
    copied = deepcopy(matrix)
    return list(map(list, zip(*copied)))

def flip_matrix(matrix):
    copied = deepcopy(matrix)
    for arr in copied:
        arr.reverse()
    return copied

def moveRight(board):
    fliped = flip_matrix(board)
    moved = moveLeft(fliped)
    return flip_matrix(moved)

def moveUp(board):
    # 1) 전치
    transposed = transpose_matrix(board)
    # 2) 왼쪽 이동
    moved = moveLeft(transposed)
    # 3) 다시 전치해서 원래 보드 방향으로 복귀
    return transpose_matrix(moved)

def moveDown(board):
    # 1) 전치
    transposed = transpose_matrix(board)
    # 2) 오른쪽 이동
    moved = moveRight(transposed)
    # 3) 원래 보드 방향 복구
    return transpose_matrix(moved)


def calc_max_number(board, step):
    global best

    current_max = find_current_max(board)
    best = max(best, current_max)

    if step > 5:
        return
    
    if (current_max ** (7 - step)) <= best:
        return
    
    calc_max_number(moveLeft(board), step + 1)
    calc_max_number(moveRight(board), step + 1)
    calc_max_number(moveUp(board), step + 1)
    calc_max_number(moveDown(board), step + 1)

calc_max_number(board_input, 1)
print(best)
 