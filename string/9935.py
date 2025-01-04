victim = input().strip()
explosion = input().strip()

checked_letters = []
explosion_length = len(explosion)

for idx in range(len(victim)):
    checked_letters.append(victim[idx])

    if ''.join(checked_letters[-explosion_length:]) == explosion:
        for _ in range(explosion_length):
            checked_letters.pop()

if checked_letters:
    print("".join(checked_letters[:]))
else:
    print('FRULA')
