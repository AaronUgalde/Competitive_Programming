import math

def bits_necesarios(n):
    """
    Calcula el número de bits necesarios para representar un número entero n en binario.
    """
    if n == 0:
        return 1
    return math.floor(math.log2(n)) + 1

print(math.sqrt(pow(10, 18)))
print(bits_necesarios(10**18))