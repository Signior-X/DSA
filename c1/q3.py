#%%
t = int(input())
while(t > 0):
    n = int(input())
    if (n > 45):
        print("-1")
    else:
        # Now we can check for possibility
        choices = [9, 8, 7, 6, 5, 4, 3, 2, 1]
        
        cs = 0
        ans = ''
        for x in choices:
            

            if (cs + x > n):
                # Number got bigger
                continue
            else:
                # Number still in range
                cs += (x)
                ans += str(x)

        ans = ans[::-1]
        print(ans)

    t-=1
