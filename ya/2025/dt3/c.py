import math

for l in range(1000):
    for r in range(1000):
        if math.comb(l, r) == 164:
            print(l, r)
