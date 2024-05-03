kabinet = int(input())

for i in range(kabinet):
    s = input().split()
    nedov = 0
    kabinet1 = [[0] * int(s[0]) for _ in range(int(s[1]))]

    if int(s[3]) != 0:
        ogr = [0] * int(s[3])
        for ogrn in range(int(s[3])):
            ogr[ogrn] = input().split()  # type: ignore

    k_teach = int(input())
    nedov += int(s[2]) - k_teach

    for j in range(k_teach):
        kom = input().split()

        if kabinet1[int(kom[2]) - 1][int(kom[3]) - 1] == 0:
            kabinet1[int(kom[2]) - 1][int(kom[3]) - 1] = int(kom[1])
            for ogrn in range(len(ogr)):
                if (
                    ogr[ogrn][1] == kom[1]
                    and ogr[ogrn][0] == "R"
                    and (ogr[ogrn][2] > kom[2] or kom[2] > ogr[ogrn][3])
                ):
                    nedov += 1
                if (
                    ogr[ogrn][1] == kom[1]
                    and ogr[ogrn][0] == "C"
                    and (ogr[ogrn][2] > kom[3] or kom[3] > ogr[ogrn][3])
                ):
                    nedov += 1
        else:
            nedov += 1
    print(nedov)
