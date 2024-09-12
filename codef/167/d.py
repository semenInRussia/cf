n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

max_a = max(a)
INF = int(1e9) + 1
dp1 = [INF] * (max_a + 1)
for i in range(n):
    dp1[a[i]] = min(dp1[a[i]], a[i] - b[i])
for i in range(1, len(dp1)):
    if dp1[i] == INF:
        dp1[i] = dp1[i - 1]
    else:
        dp1[i] = min(dp1[i], dp1[i - 1])

dp2 = [0] * (max_a + 1)
for x in range(max_a + 1):
    d = dp1[x]
    if d != INF:
        dp2[x] = 1 + dp2[x - d]

def f(x):
    cnt = max(0, x - max_a) // dp1[max_a]
    x -= cnt * dp1[max_a]
    if x > max_a:
        x -= dp1[max_a]
        cnt += 1
    return dp2[x] + cnt

print(2 * sum(map(f, c)))
