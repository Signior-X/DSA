n, m = list(map(int,input().split()))

inp = []

for i in range(n):
    inp.append(list(map(int,input().split())))


ans = 0
for i in range(n):
    
    # find the minimum in the row
    mn = inp[i][0]
    for j in inp[i]:
        mn = min(mn, j)

    ans = max(ans, mn)

print(ans)
