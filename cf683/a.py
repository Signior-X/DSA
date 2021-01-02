t = int (input())

while t>0:

    inp = int(input())
    ans = [i for i in range(1, inp + 1)]
    print(inp)
    print(*ans)

    t-=1
