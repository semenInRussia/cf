symbols = ""

for i in range(32, 127):
    if chr(i) == '\\' or chr(i) == '"':
        continue
    symbols += chr(i)

assert len(set(symbols)) == len(symbols)

idx = 0

al = {}

for a in range(10):
    al[str(a)] = symbols[idx]
    idx += 1

for a in range(10):
    for b in range(10):
        if idx == len(symbols):
            break
        al[str(a) + str(b)] = symbols[idx]
        idx += 1


def encode(t):  # t - text from 0-9
    t += '$'
    i = 0
    ans = ""
    while i < len(t) and t[i] != '$':
        a = t[i]
        b = t[i + 1]
        ab = a + b
        if ab in al:
            ans += al[ab]
            i += 2
        else:
            ans += al[a]
            i += 1
    return ans


tal = {v: k for k, v in al.items()}


def decode(t):
    ans = ""
    for c in t:
        ans += tal[c]
    return ans


f = open("data.txt")
c = 0
for line in f:
    if not line:
        break
    d, t = line.strip().split(".")
    print(encode(t.strip()))
    assert decode(encode(t.strip())) == t.strip()

f.close()
