#%%
import math
from bisect import bisect_right

def printDivisors(n) : 
      
    # Note that this loop runs till square root 
    i = 1
    lst = []
    while i <= math.sqrt(n): 
          
        if (n % i == 0) : 
              
            # If divisors are equal, print only one 
            if (n / i == i) : 
                lst.append(i)
            else : 
                # Otherwise print both 
                lst.append(i)
                lst.append(n//i)

        i = i + 1
    
    return sorted(lst)

t = int(input())
for _ in range(t):

    n = int(input())

    cb = n**(1/3)
    divs = printDivisors(n)
    # print(divs)

    ind = bisect_right(divs, cb*2)
    final_divs = divs[:ind]

    # print(final_divs)

    ans = "NO"

    for x in range(1, int(cb) + 1):
        for y in final_divs:
            if y-x > 0:
                # print(x**3 + (y-x)**3)
                if x**3 + (y-x)**3 == n:
                    ans = "YES"
                    break
        
    print(ans)
