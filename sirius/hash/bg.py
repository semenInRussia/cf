import random


def create_test(s: str):
    with open("input.txt", "w") as f:
        f.write(s)


al = "abz"


def gen_str(sz=100) -> str:
    s = ""
    for _ in range(sz):
        s += random.choice(al)
    return s


sz = 8
tt = 100

import os


def check(s: str, n: int) -> bool:
    if n == -1:
        return not any((check(s, n) for n in range(1, len(s) + 1)))
    d = s[-n:] + s[:-n]
    return d[::-1] == d


while True:
    s = gen_str(sz)
    create_test(s)
    answ = int(os.popen("./a.out").read())
    if not check(s, answ):
        print(s)
        print(answ)
        assert False
    print("OK!")
