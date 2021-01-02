# This question was one of them which seems difficult but was simple
# We need to think in some other ways to solve these kinds
# here we assumed the answer and simply did brute force considering the constraints
# https://codeforces.com/problemset/problem/1360/F


tests = int(input())

while(tests > 0):
    n, l = list(map(int, input().split()))
    inps = []
    for i in range(n):
        inps.append(input())
    
    # Now let's assume the answer to be the first string
    # or the first string with one character differing from rest others

    ans = inps[0]
    # print(ans)

    finalAns = '-1'

    for pos in range(l):
        # now we will change string at pos to some other
        
        for j in range(97, 123):
            ch = chr(j)
            letstr = ans[:pos] + ch + ans[pos+1:]
            # print(letstr)

            # now check for difference of letstr with each string and if difference is more than one break

            flag = True

            for curstr in inps[1:]:
                c = 0
                for x,y in zip(letstr, curstr):
                    if (x != y):
                        c+=1
                    if c > 1:
                        flag = False
                        break
                if flag == False:
                    break    # as already diagreed with the condition
            
            if (flag == True):
                # Yes we found one
                # print("Found one", letstr)
                finalAns = letstr
                break
    
    print(finalAns)

    tests -= 1
