import random
import subprocess


def gen_input_txt():
    with open("input.txt", "w") as f:
        n = 1_000_00
        A = 1
        B = 2
        ts = [random.randint(-1_000_000_000, 1_000_000_000) for _ in range(n)]
        print(n, A, B, *ts, file=f)


skip_mode = False

while True:
    gen_input_txt()

    exp = subprocess.getoutput("cat input.txt | ./exp").strip()
    act = subprocess.getoutput("cat input.txt | ./ac").strip()

    if exp == act and skip_mode:
        continue

    print(f"{exp} == {act}:")

    op = input("print file? (1 - yes, c - skip)")

    if op == "1":
        print(subprocess.getoutput("cat input.txt").strip())
        op = input("(c - skip mode, Enter - next)")
    if op == "c":
        skip_mode = True
