n = 6

a = [
    [16, -3, 6, 3, 15, -2],
    [10, 11, 9, 13, 17, 15],
    [6, -13, 0, -2, 10, 5],
    [1, -9, -3, 4, -14, -8],
    [-2, 4, 7, -3, 0, -12],
    [-15, -7, -6, -8, -10, -5],
    [-16, -11, 1, 1, -12, -3],
]

m = len(a[0])

for row in a:
    assert m == len(row)

j = -1

for i in range(len(a)):
    if j == -1 or sum(a[j]) < sum(a[i]):
        j = i

print("j=", j)

b = [a[i] for i in range(len(a)) if i != j]
expected = a[j]


for msk in range(1 << len(b)):
    actual = [0 for _ in range(m)]
    for j in range(len(b)):
        for i in range(m):
            if (msk >> j) & 1:
                actual[i] -= b[j][i]
            else:
                actual[i] += b[j][i]
    if actual == expected:
        for j in range(m):
            if (msk >> j) & 1:
                print("-", end="")
            else:
                print("+", end="")
        print()
