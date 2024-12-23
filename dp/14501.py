import sys
from functools import lru_cache
import math

sys.setrecursionlimit(10 ** 5)

N = int(input())
T = [ 0 ]
P = [ 0 ]
MINUS_INF = -987654321

# n일차 포함 그 이후로 벌 수 있는 최대값 반환
@lru_cache(maxsize = 10 ** 5)
def get_max_price(n):
    if n > N:
        return 0
    
    if n + T[n] > N + 1:
        return get_max_price(n + 1)

    # n일차를 건너뛰기 or n일차 상담을 하고 p[n] 을 받는 것 중 max 고름
    return max(get_max_price(n + 1), get_max_price(n + T[n]) + P[n])


for _ in range(N):
    t, p = [int(n) for n in sys.stdin.readline().split()]
    T.append(t)
    P.append(p)

dp = [0 for i in range(N + 2)]

for i in range(1, N + 1):
    for j in range(i + T[i], N + 2):
        dp[j] = max(dp[i] + P[i], dp[j])

# top-down
# print(get_max_price(1))

# bottom-up
print(dp[N + 1])