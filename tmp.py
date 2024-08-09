def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


print(is_prime(11))  # True
print(is_prime(1))  # False
print(is_prime(int(1e9 + 7)))  # ..
