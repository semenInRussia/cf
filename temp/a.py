# T(N) = p * (p + 1) * (a + 1)
# Q(N) = p * (p + 1) * (a + 2)

# T(N) + T(N)/(a+1) = 264
# T(N)/(a+1) = 66
# a+1 = T(N) / 66
# a = 2

#

a = (2**10) * (2**5) * (169)
print(a)


def count(x):
    d = set()
    for y in range(1, int(x**0.5) + 10):
        if x % y == 0:
            d.add(y)
            d.add(x // y)
    # print(d)
    return len(d)


b = 1889568 * 169
c = (1 << 66) * (169)
print(count(a))
print(count(a * 13))
print(count(b))
print(count(b * 13))

print(min(a, b))
