# 6 9 8 5 3 1 2
# 400 432 433 434 435 438 439 450 470 480 483 700 800 503 502 502 301 301 100 200 203 204

import random

n = random.randint(10, 20)
p = random.randint(0, n)
q = random.randint(p, n)

arr = []

with open("input.txt") as f:
    print(file=f, end=" ")
