## DP Problem mainly
# https://codeforces.com/problemset/problem/1295/C

tests = int(input())
while(tests > 0):

    s = input()
    t = input() # The end goal to be created

    # we will have a pointer to each element of each next element with its position
    # reverse loop and keep sotring and updating the dictionaries

    dpList = []
    i = len(s) - 1
    cd = {}

    while(i>=0):
        
        cd[s[i]] = i
        dpList.append(cd.copy())

        i-=1

    # dpList contains the nearest next index of each character
    dpList = dpList[::-1]
    dpList.append({})

    # print(dpList)

    # Now we will loop and if at any point the key is found continue using that one and if not found
    # break and start the next iteration
    # always check for i+1 in the dpList for the next one to go on
    ans = 1
    i = 0
    ci = 0

    while(i<len(t)):
        val = t[i]

        nextIndex = len(s) + 1
        # find the index of a
        if val in dpList[ci]:
            # Found the current element at
            ci = dpList[ci][val] + 1
            # print(val, ci)
            i += 1
        
        else:
            # Element not found

            if ci == 0:
                ans = -1
                break

            # 1. The element can be at a previous one, so restart the loop
            ans += 1
            ci = 0

    print(ans)



    tests -= 1
