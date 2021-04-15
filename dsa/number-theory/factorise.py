# Here we will factorise using the seive method

from minprime import minPrime

def factor(x):
    res = []

    while (x != 1):
        res.append(minPrime[x])
        x //= minPrime[x]
    
    return res

print(factor(28))
