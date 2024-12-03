n = int(input())
A = int(input())
B = int(input())

t1 = int(input())
t2 = int(input())

x = (t1 + t2) // (A + B) + 1
d = [0]

def check(x):
    return max(A, B) * x > max(t1, t2) and (A + B) * x > 2 * min(t1, t2)


while not check(x):
    x += 1

print(x)
