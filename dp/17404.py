import sys
sys.setrecursionlimit(10 ** 6)

INF = 10 ** 7

red_first_dp = [[0] * 1000 for _ in range(1000)]
green_first_dp = [[0] * 1000 for _ in range(1000)]
blue_first_dp = [[0] * 1000 for _ in range(1000)]
costs = []

N = int(sys.stdin.readline())

for _ in range(N):
    costs.append([int(n) for n in sys.stdin.readline().split()])

red_first_dp[0] = [costs[0][0], INF, INF]
green_first_dp[0] = [INF, costs[0][1], INF]
blue_first_dp[0] = [INF, INF, costs[0][2]]

for i in range(1, N):
    red_first_dp[i][0] = min(red_first_dp[i - 1][1], red_first_dp[i - 1][2]) + costs[i][0]
    red_first_dp[i][1] = min(red_first_dp[i - 1][0], red_first_dp[i - 1][2]) + costs[i][1]
    red_first_dp[i][2] = min(red_first_dp[i - 1][0], red_first_dp[i - 1][1]) + costs[i][2]

    green_first_dp[i][0] = min(green_first_dp[i - 1][1], green_first_dp[i - 1][2]) + costs[i][0]
    green_first_dp[i][1] = min(green_first_dp[i - 1][0], green_first_dp[i - 1][2]) + costs[i][1]
    green_first_dp[i][2] = min(green_first_dp[i - 1][0], green_first_dp[i - 1][1]) + costs[i][2]

    blue_first_dp[i][0] = min(blue_first_dp[i - 1][1], blue_first_dp[i - 1][2]) + costs[i][0]
    blue_first_dp[i][1] = min(blue_first_dp[i - 1][0], blue_first_dp[i - 1][2]) + costs[i][1]
    blue_first_dp[i][2] = min(blue_first_dp[i - 1][0], blue_first_dp[i - 1][1]) + costs[i][2]

print(min(red_first_dp[N - 1][1], red_first_dp[N - 1][2], green_first_dp[N - 1][0], green_first_dp[N - 1][2], blue_first_dp[N - 1][0], blue_first_dp[N - 1][1]))