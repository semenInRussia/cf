ans = 0

for x in range(321):
    s = str(x)
    ok = 1
    for i in range(1, len(s)):
        if s[i - 1] == s[i]:
            ok = 0
            break
    ans += ok

print(ans)
