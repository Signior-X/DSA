def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

print(gcd(23, 46))

def gcd2(a, b):
    if b == 0:
        return a
    else:
        return gcd(a-b, b)

print(gcd2(46, 56))
