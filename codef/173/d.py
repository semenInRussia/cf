arr = [-1, +1, -1, -1, -1, -1, +1, +1, +1]

print("sum = ", sum(arr))

s = set()

for i in range(len(arr)):
    for j in range(i + 1, len(arr) + 1):
        s.add(sum(arr[i:j]))

print(sorted(s))
