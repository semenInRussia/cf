# semenInRussia 2024
import sys

d = {}
k = int(input())
n = int(input())

ok = 0

for _ in range(n):
    s = input()
    if s not in d:
        d[s] = 0
    d[s] += 1
    if d[s] >= (k // 2):
        ok = 1

if not ok:
    print("NO")
    sys.exit(0)

ans = []
for s, c in d.items():
    if c >= (k // 2):
        ans.append(s)
ans.sort()
for x in ans:
    print(x)
