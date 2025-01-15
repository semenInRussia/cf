n = int(input())
x = int(input())


def f(n, x):
    p10 = 10**n
    p2 = 2**x

    k = ((p10 // 10) + p2 - 1) // p2
    h = (p10 + p2 - 1) // p2

    if n == 1:
        return (9 // p2) + 1
    else:
        return max(h - k, 0)


# f(3, 4)

# n = 1

# nums = list(range(0, 10))

# for x in range(1, 60):
#     print("---")
#     print(x)
#     cnt = 0
#     for y in nums:
#         cnt += y % (1 << x) == 0
#     print(cnt, f(n, x))
#     assert cnt == f(n, x)

print(f(n, x))
