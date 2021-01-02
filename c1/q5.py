#%%

def findComb(a):
    return (a*(a-1))//2

t = int(input())
while(t > 0):
    n = int(input())
    inp = list(map(int, input().split()))

    dpArray = [0 for i in range(n+3)]

    for x in inp:
        dpArray[x] += 1
    
    # print(dpArray)

    ans = 0
    for x in inp:
        # Now we have three cases

        dpArray[x] -= 1

        # print(x)
        # print(dpArray)

        ans += (dpArray[x+2])*(dpArray[x+2] - 1)//2
        ans += (dpArray[x+2])*(dpArray[x+1])
        ans += (dpArray[x+2])*(dpArray[x])


        ans += (dpArray[x+1])*(dpArray[x+1] - 1)//2
        ans += (dpArray[x+1])*(dpArray[x])
        ans += (dpArray[x+1])*(dpArray[x-1])


        ans += (dpArray[x])*(dpArray[x] - 1)//2
        ans += (dpArray[x])*(dpArray[x-1])
        if (x>=2):
            ans += (dpArray[x])*(dpArray[x-2])

        ans += (dpArray[x-1])*(dpArray[x-1] - 1)//2
        
        if (x>=2):
            ans += (dpArray[x-1])*(dpArray[x-2])

        if (x>=2):
            ans += (dpArray[x-2])*(dpArray[x-2] -1)//2
        
    #     print('ans', ans)

    # print(dpArray)
    print(ans)

    t-=1
