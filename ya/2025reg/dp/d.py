def check(x: int, k: int) -> bool:
    r = 1
    for c in str(x):
        r *= int(c)
    return r <= k


tt = int(input())

for _ in range(tt):
    n, k = map(int, input().split())
    # print("n,k:", n, k)
    ans = 0
    for x in range(1, n + 1):
        ans += check(x, k)
    print(ans)
