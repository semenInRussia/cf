a = [-3, 2, -4, 1, -5]

ans = 0

for l in range(len(a)):
    for r in range(l + 1, len(a) + 1):
        ans += min(a[l:r] + [0])

print(ans)
