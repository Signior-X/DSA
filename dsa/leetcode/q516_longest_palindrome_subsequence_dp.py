#%% The O(n^2) solution using dp array for longest subsequence
# palindrome

# dp for longest subesquence problem in O(n^2)

#%%

def solve(s):

    l = len(s)

    dp = []
    for i in range(l):
        lst = [1 if i==j else 0 for j in range(l)]
        dp.append(lst)

    # print(dp)

    # making the diagonals as one

    # now start
    diff = 1
    while(diff < l):
        # start from here

        i = 0
        j = i + diff

        while(j<l):
            if s[i] == s[j]:
                print(i, j) 
                dp[i][j] = 2 + dp[i+1][j-1]
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
            
            i += 1
            j += 1
        
        diff += 1

        # for x in dp:
        #     print(*x)
        # print()

    # print(dp)
    return dp[0][l-1]

solve('abbacdd')
