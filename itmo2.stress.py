C = 14
x = 12
s = 0

for j in range(C):
    print(x)
    s += x

    if x & 1:
        x = 3 * x + 1
    else:
        x = x // 2

print(s)
