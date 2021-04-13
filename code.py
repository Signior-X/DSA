#%%
def solve(A, B, C):
    # loop in B
    n = len(A)
    specialValue = A[0]
    
    for i in range(1, len(A)):
        specialValue = specialValue ^ A[i]
    
    # so we need c elements to be greater than
    # specialValue using b moves from left and right side
    # print(specialValue)
    
    zero_array = [0 if (x >= specialValue) else (specialValue - x) for x in A]
    # print(zero_array)
    # create a dp array for number of zeroes

    dp = [[0]*n for i in range(n)]
    for i in range(n):
        dp[i][i] = 1 if zero_array[i] == 0 else 0
    
    for i in range(n):
        for j in range(i+1, n):
            dp[i][j] = dp[i][j-1] + dp[j][j]

    # print(dp)

    ans = 0
    # so dp is an upper triangular matrix with the values
    # of how much values are there from i to j which statisfies

    # now we want to have arrays of length c
    diff = C - 1
    while(diff < n):
        i = 0
        j = i + diff

        already_used = n - (diff + 1)
        bal = B - already_used
        # print(bal)

        # skipping the lengths which are not possible
        if bal < 0:
            diff += 1
            continue

        while(j < n):
            # print(i, j)
            
            g0 = dp[i][j] - C
            # check how much values satisfy
            # we will check it using the balance
            if g0 >= 0:
                ans += 1
            elif g0 >= -2:
                # find the min of two extremes
                # if both are zeroes nothing can be done
                # if the extremes are not zero
                if zero_array[i] != 0 and zero_array[j] != 0:
                    # both are non zero
                    if g0 == -1:
                        mn = min(zero_array[i], zero_array[j])
                        if mn <= bal:
                            ans += 1
                    else:
                        #g0 is -2
                        # both should be able to do
                        s = zero_array[i] + zero_array[j]
                        if s <= bal:
                            ans += 1

                elif zero_array[i] != 0:
                    # the j one was zero
                    
                    if g0 == -1 and zero_array[i] <= bal:
                        ans += 1
                elif zero_array[j] != 0:
                    # the i one was zero
                    
                    if g0 == -1 and zero_array[j] <= bal:
                        ans += 1

            j += 1
            i += 1

        diff += 1

    return ans

solve(
    [88, 4, 76, 35, 87, 65, 31],
    1,
    3
)
