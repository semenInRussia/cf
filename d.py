# https://codeforces.com/problemset/problem/1985/G
mod = int(1e9 + 7)
tt = int(input())
for _ in range(tt):
    l, r, k = map(int, input().split())
    v = (9 // k) + 1
    print((pow(v, r, mod) - pow(v, l, mod) + mod) % mod)
