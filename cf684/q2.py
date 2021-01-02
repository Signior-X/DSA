tests = int(input())

while(tests > 0):
    n = int(input())

    inp = list(map(int, input().split()))

    lst = [2**i for i in range(30)]
    # print(lst)

    ans = []

    for x in inp:

        # find the minimum difference with 2 vaala value from lst
        mn = 1000000005
        mnv = 1
        for y in lst:
            if abs(y-x) < mn:
                mn = abs(y-x)
                mnv = y
        
        ans.append(mnv)
    
    print(*ans)

    tests -=1
