import itertools

p = tuple(range(1, 7))

cnt = 0
good = 0

for a, b, c in itertools.product(p, repeat=3):
    if a + b + c == 9:
        cnt += 1
        good += b == 6

print(good / cnt)


# 1: 2, 5 | 5, 2
# 2:
