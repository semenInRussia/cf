import random
import subprocess

alphabet = "ab"

while True:
    n1 = random.randint(1, 6)
    n2 = random.randint(1, n1)

    wrd1 = "".join([random.choice(alphabet) for _ in range(n1)])
    wrd2 = "".join([random.choice(alphabet) for _ in range(n2)])

    print(wrd1)
    print(wrd2)
    print(subprocess.getoutput(f"echo {wrd1} {wrd2} | ./a.out"))
    print("---")
    input()
