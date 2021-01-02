#%%
t = int(input())
while(t > 0):
    n = int(input())
    inp = list(map(int, input().split()))

    c = n//2
    ans = []

    for i in range(c):
        ans.append(inp[i])
        ans.append(inp[-i-1])
    
    if (n%2 != 0):
        ans.append(inp[c])

    print(*ans)

    t-=1
