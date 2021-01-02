#%%
t = int(input())
while(t > 0):
    n = int(input())
    st = input()

    if len(st) < 4:
        print("NO")
    else:
        # Now start checking
        if (st[:4] == '2020'):
            print("YES")
        elif (st[:3] == '202' and st[-1] == '0'):
            print("YES")
        elif (st[:2] == '20' and st[-2:] == '20'):
            print("YES")
        elif (st[0] == '2' and st[-3:] == '020'):
            print("YES")
        elif (st[-4:] == '2020'):
            print("YES")
        else:
            print("NO")    

    t-=1
