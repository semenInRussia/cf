s = "aaba"

for l in range(len(s)):
    for r in range(l + 1, len(s) + 1):
        print(s[l:r])
