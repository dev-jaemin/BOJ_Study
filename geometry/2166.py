import sys

sys.setrecursionlimit(10 ** 6)

def calc_area(vertex_list):
    v_list = vertex_list
    v_list.append(v_list[0])
    sum_a = 0
    sum_b = 0

    for index, _ in enumerate(v_list):
        if index >= len(v_list) - 1:
            break

        sum_a += v_list[index + 1][0] * v_list[index][1]
        sum_b += v_list[index][0] * v_list[index + 1][1]
    
    return abs(sum_a - sum_b) * 0.5


def main():
    N = int(sys.stdin.readline())

    vertex_list = []

    for _ in range(0, N):
        x, y = sys.stdin.readline().split()
        vertex_list.append([int(x), int(y)])
    
    print(calc_area(vertex_list))

main()