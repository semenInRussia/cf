import sys

sys.set_int_max_str_digits(15000)

n = int(input())

f = [[0 for _ in range(4)] for _ in range(n + 100)]

f[1][2] = 1
for i in range(2, n + 1):
    f[i][0] = f[i - 1][2] * 2
    f[i][1] = f[i - 1][2]
    f[i][2] = f[i - 1][3] + f[i - 1][1]
    f[i][3] = f[i - 1][2]


print(f[n][0])
