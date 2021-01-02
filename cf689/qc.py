tests = int(input())

while tests:

    l, m = list(map(int, input().split()))
    inp = list(map(int, input().split()))

    ops = []
    for _ in range(m):
        ops.append(list(map(float, input().split())))

    # Now after performing an operation it can be
    # 1 or 0 (In one case it got sorted)
    # 0 or 0 (In both cases not sorted)

    st = l-1
    for i in range(l-1, -1, -1):
        # check if the array will become sorted with i prefix operation or not
        if (inp[i] == i+1):
            st = i - 1
        else:
            break
    
    if st == -1:
        print('1.000000')
    else:
        # not already sorted
        ans = 1.0

        for x in ops:
            # print(x)

            if x[0] <= st:
                # this can be sorted, has no effect
                continue
            else:
                ans *= (1-x[1])
        
        print(1-ans)

    tests -= 1
