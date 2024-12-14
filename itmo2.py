d = {}

N = int(1e5)
b = [0 for _ in range(N)]

C = 10**10
x = -5029

# C = 14
# x = 12

j = -1
k = -1

b[0] = x
i = 1
while x != 0:
    if i % 500_000 == 0:
        print(i)
    if x & 1:
        x = 3 * x + 1
    else:
        x = x // 2

    j = d.get(x)
    if j is not None:
        k = i - j
        break

    d[x] = i
    b[i] = x
    i += 1

ans = -1

if k > 0:
    assert j is not None
    c2 = C - j
    ans = sum(b[: (j + (c2 % k))]) + (c2 // k) * sum(b[j:])

print(ans)
