N = 62
p = [0 for _ in range(N)]

p[0] = 1
for i in range(1, N):
    p[i] = p[i - 1] * 2 + 1


def f(n: int, i: int) -> int:
    sz = p[n]
    assert i < sz
    assert sz & 1

    if sz == 1:
        return 0  # валет
    mid = sz // 2
    if mid == i:
        return 3  # туз
    if i < mid:
        return f(n - 1, i)
    return (f(n - 1, sz - i - 1) + 1) % 4


# stress tests

# def seq(n: int) -> list[int]:
#     if n == 0:
#         return [0]
#     sq = seq(n - 1)
#     k = len(sq)
#     sq.append(3)  # туз
#     for i in range(k - 1, -1, -1):
#         sq.append((sq[i] + 1) % 4)
#     return sq

# for n in range(0, 10):
#     sq = seq(n)
#     for k in range(0, len(sq)):
#         ok = f(n, k) == sq[k]
#         if not ok:
#             print(n, k)
#         assert ok

# print("PASSED")

n, k = map(int, input().split())

s = "ВДКТ"
j = f(n - 1, k)
print(s[j])
