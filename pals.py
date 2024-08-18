ans = 0
for x in range(1000000):
    s = str(x)
    if s[::-1] == s:
        print(s)
        ans += 1

print("---")
print(ans)
