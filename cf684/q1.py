tests = int(input())

while(tests > 0):

    a, b, c = list(map(int, input().split()))

    m = min(a, b, c)
    # maximum can be m multiple of 7

    ans = "NO"

    if (a + b + c) % 9 == 0:
        # mulitple of 9
        d = (a + b + c)/9

        if (m >= d):
            ans = "YES"

    print(ans)



    tests -=1
