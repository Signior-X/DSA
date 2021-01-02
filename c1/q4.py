tests = int(input())
while(tests > 0):
    n = int(input())
    inp = list(map(int, input().split()))

    s = sum(inp)

    minAns = n-1

    for i in range(1, s):
        # Now we will check if n is possible or not

        if (s%i == 0):
            # possible as i is a factor of s
            # each should be i and the count should be s/i
            cnt = 0
            v = 0
            ans = 0
            
            for val in inp:
                v += val
                ans += 1 # consider it as a swap

                if(v>i):
                    ans = n-1
                    break

                if(v==i):
                    cnt +=1
                    v = 0
                    ans -=1
            
            if(cnt == s/i):
                # This can be an answer
                # print("check here", s, i)
                minAns = min(ans, minAns)
    
    print(minAns)
    
    tests -= 1
