# 23, 60000

from mpmath import *

n = 56
s = 100_000

mp.dps = s + 200

p = mpf(1) / mpf(3)

# exp 973

print(str(mpf(n)**p)[:s + 2])
