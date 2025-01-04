import sys

def is_palindrome(n):
    ret = True

    for idx in range(len(n) // 2):
        if n[idx] != n[len(n) - idx - 1]:
            ret = False
            break
    
    return ret


while True:
    n = sys.stdin.readline()[:-1]

    if n == '0':
        break

    print('yes' if is_palindrome(n) else 'no')