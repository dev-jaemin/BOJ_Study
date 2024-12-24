n, k = [int(c) for c in input().split()]
arr = []

for _ in range(n):
    arr.append(int(input()))

INF = 987654321
dp = [INF for i in range(k + 1)]
dp[0] = 0

for coin in arr:
    for value in range(coin, k + 1):
        dp[value] = min(dp[value], dp[value - coin] + 1)

print(-1 if dp[k] == INF else dp[k])