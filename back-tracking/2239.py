import sys
sys.setrecursionlimit(10 ** 6)

def count_zero(matrix):
    count = 0
    for row in matrix:
        for value in row:
            if value == 0:
                count += 1
    return count

def make_zero_list(matrix):
    zero_list = []
    for row_index, row in enumerate(matrix):
        for col_index, value in enumerate(row):
            if value == 0:
                zero_list.append((row_index, col_index))
    return zero_list

def chk_row(matrix, row_index):
    value_set = set()
    for value in matrix[row_index]:
        if value != 0 and value in value_set:
            return False
        value_set.add(value)
    return True

def chk_column(matrix, col_index):
    value_set = set()
    for row in range(9):
        value = matrix[row][col_index]
        if value != 0 and value in value_set:
            return False
        value_set.add(value)
    return True

def chk_area(matrix, row_index, col_index):
    value_set = set()
    start_row, start_col = 3 * (row_index // 3), 3 * (col_index // 3)
    for row in range(start_row, start_row + 3):
        for col in range(start_col, start_col + 3):
            value = matrix[row][col]
            if value != 0 and value in value_set:
                return False
            value_set.add(value)
    return True

def can_sudoku(matrix, row_index, col_index):
    return chk_row(matrix, row_index) and chk_column(matrix, col_index) and chk_area(matrix, row_index, col_index)

def can_complete_sudoku(zero_list, zero_index):
    if zero_index == len(zero_list):
        return True

    row, col = zero_list[zero_index]
    for candidate in range(1, 10):
        if can_sudoku(input_sudoku, row, col):
            input_sudoku[row][col] = candidate

            if can_complete_sudoku(zero_list, zero_index + 1):
                return True
            input_sudoku[row][col] = 0

    return False

def print_matrix(matrix):
    for row in matrix:
        print("".join(map(str, row)))


input_sudoku = []
for _ in range(9):
    input_line = sys.stdin.readline().rstrip()
    row = list(map(int, input_line))
    input_sudoku.append(row)

zero_list = make_zero_list(input_sudoku)

if can_complete_sudoku(input_sudoku, zero_list, 0):
    print_matrix(input_sudoku)
else:
    print("No solution exists")
