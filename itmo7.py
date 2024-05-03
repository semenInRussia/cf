import sys

minput = input


kab = int(minput())

for i in range(kab):
    s = minput().split()
    n = 0
    k1 = [[0] * int(s[0]) for i in range(int(s[1]))]
    ogran = [0] * int(s[3])

    if int(s[3]) != 0:
        for og in range(int(s[3])):
            ogran[og] = minput().split()
    ukaz = int(minput())
    n += int(s[2]) - ukaz

    for j in range(ukaz - 1):
        # order = minput().split()
        order = minput().split()

        if k1[int(order[2]) - 1][int(order[3]) - 1] == 0:
            k1[int(order[2]) - 1][int(order[3]) - 1] = int(order[1])
            if int(s[3]) != 0:
                for og in range(len(ogran)):
                    if (
                        ogran[og][1] == order[1]
                        and ogran[og][0] == "R"
                        and (ogran[og][2] > order[2] or order[2] > ogran[og][3])
                    ):
                        n += 1
                    if (
                        ogran[og][1] == order[1]
                        and ogran[og][0] == "C"
                        and (ogran[og][2] > order[3] or order[3] > ogran[og][3])
                    ):
                        n += 1
        else:
            n += 1
    print(n)
