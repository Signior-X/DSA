# Binary exponentiation is fast and can work in log n time

import time

def binary_exponentiation(x, n):
    
    result = 1
    while (n > 0):
        if (n%2 == 1):
            result = result * x
        x = x*x
        n = n // 2
    
    return result

# However in other languages for very large answers, it will return garbage value, so we use modular exponentiation

if __name__ == '__main__':

    a = 30000000000
    b = 1000000

    yt = time.time()
    exp1 = a**b

    print(time.time() - yt)


    xt = time.time()
    exp2 = binary_exponentiation(a, b)

    print(time.time() - xt)


    


