n = int(input())

k = int(input())

ndigs = len(str(n - 1))
kdigs = len(str(k))

dig = k % 10

print(ndigs * (dig - 1) + kdigs)
