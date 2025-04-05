# 8 + (0.2)


def main():
    n, m = map(int, input().split())
    l = -1
    r = n + 1
    al = (n * m) * (n * m + 1) // 2

    while r - l > 1:
        mid = (l + r) // 2
        p1 = ((mid - 1) * m + 1) * ((mid - 1) * m) // 2
        p2 = al - p1
        if p1 - p2 == 0:
            l = mid
            r = mid
            break
        if p1 - p2 < 0:
            l = mid
        else:
            r = mid

    p1 = ((l - 1) * m + 1) * ((l - 1) * m) // 2
    p2 = al - p1
    p3 = ((r - 1) * m + 1) * ((r - 1) * m) // 2
    p4 = al - p3
    ans1 = min(abs(p1 - p2), abs(p4 - p3))

    i = 0
    if abs(p1 - p2) < abs(p4 - p3):
        i = l - 1
    else:
        i = r

    col = (1 + m * (n - 1) + 1) * n // 2

    # pppppppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeennnnnnnnnnnnnnnnniiiiiiiiiiiiiiiiiiiiis

    l = -1
    r = m + 1
    while r - l > 1:
        mid = (l + r) // 2
        p1 = col * mid + n * (mid - 1) * mid // 2
        p2 = al - p1
        if p1 - p2 == 0:
            l = mid
            r = mid
            break
        if p1 - p2 < 0:
            l = mid
        else:
            r = mid

    p1 = col * l + n * (l - 1) * l // 2
    p2 = al - p1
    p3 = col * r + n * (r - 1) * r // 2
    p4 = al - p3
    ans2 = min(abs(p3 - p4), abs(p1 - p2))
    j = 0
    if abs(p3 - p4) <= abs(p1 - p2):
        j = r
    else:
        j = l
    if ans1 < ans2:
        print("H", i)
    else:
        print("V", j + 1)


for t in range(int(input())):
    main()
