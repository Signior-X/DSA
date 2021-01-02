tests = int(input())

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

while tests > 0:

    n, m = list(map(int, input().split()))
    ms = list(map(int, input().split()))

    # find the gcd of ms
    gc = gcd(ms[0], 0)
    for x in ms:
        gc = gcd(gc, x)
    
    # max people can left is gc
    # print(gc)

    if n < gc:
        # already below gc
        # print('Think of')
        # now find the divisor of gc starting by decreasing n
        left = n
        num = n
        while (num>0):
            if gc%num == 0:
                left = num
                break
            num -= 1
        
        print(n - left)

    else:
        print(n - gc)

    tests -= 1

