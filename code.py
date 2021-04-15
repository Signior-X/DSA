import math

def oddDivisors(n):

    root_n = n**0.5
    if root_n**2 == n:
        return True
    else:
        return False

def solve(n):
    print(n, math.sqrt(n))


for __ in range(int(input())):
    n = int(input())
    solve(n-100)