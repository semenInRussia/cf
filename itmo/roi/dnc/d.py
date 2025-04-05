import sys

sys.set_int_max_str_digits(500000)

with open("multiply.in", "r") as f:
    a = int(f.readline())
    b = int(f.readline())

with open("multiply.out", "w") as f:
    print(a * b, file=f)
