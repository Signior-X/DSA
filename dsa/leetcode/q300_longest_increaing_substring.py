#%%
arr = [10, 22, 10, 33, 21, 50, 41, 60, 80]

# subsequence, it's maximum that is the right most
dp = []

def binary_search_in_dp(val):
    low = -1
    high = len(dp)

    while(high-low > 1):
        md = (low + high) // 2
        # print(md, low, high)

        # Chaning this changes it to increasing and non decreaing!!!!
        if dp[md] >= val:
            high = md
        else:
            low = md
    
    return low

for x in arr:
    val = binary_search_in_dp(x)
    print(val)

    if val != -1:
        if dp[val] > x:
            dp[val] = x
        else:
            # Add it up
            if len(dp) > val + 1:
                dp[val+1] = x
            else:
                dp.append(x)
    else:
        if len(dp):
            dp[0] = x
        else:
            dp.append(x)

    print(dp)

