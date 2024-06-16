lazy = {}

def f(a):
    if a in lazy:
        return lazy[a]
    if a <= 1:
        lazy[a] = a
    else:
        lazy[a] = f(a - 1) + f(a - 2)
    return lazy[a]

for i in range(8):
    print(f(i), end=" ")
