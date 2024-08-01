import sys

sys.setrecursionlimit(10 ** 7)

str1 = sys.stdin.readline()[:-1]
str2 = sys.stdin.readline()[:-1]


def lcs():
    len1 = len(str1)
    len2 = len(str2)

    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    lcs_string = [[''] * (len2 + 1) for _ in range(len1 + 1)]

    for a in range(1, len1 + 1):
        for b in range(1, len2 + 1):
            if str1[a - 1] == str2[b - 1]:
                dp[a][b] = dp[a - 1][b - 1] + 1
                lcs_string[a][b] = lcs_string[a - 1][b - 1] + str1[a - 1]
                continue
            
            if dp[a - 1][b] > dp[a][b - 1]:
                dp[a][b] = dp[a - 1][b]
                lcs_string[a][b] = lcs_string[a - 1][b]
            else:
                dp[a][b] = dp[a][b - 1]
                lcs_string[a][b] = lcs_string[a][b - 1]
    
    return (dp[len1][len2], lcs_string[len1][len2])


lcs_length, lcs_string = lcs()

print(lcs_length)
if lcs_length > 0:
    print(lcs_string)