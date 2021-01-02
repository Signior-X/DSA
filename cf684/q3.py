tests = int(input())

while(tests > 0):
    n = int(input())

    ts = []
    xs = []

    mpArray = [-1 for i in range(25)]

    for i in range(n):
        t, x = list(map(int, input().split()))
        ts.append(t)
        xs.append(x)
        mpArray[t] = x
    
    positions = [0]
    i = 0
    while(i < len(mpArray)):

        if mpArray[i] != -1:
            # This means start moving 
            # from last position to the current one

            cp = positions[i]
            fp = mpArray[i]

            if fp > cp:
                # move forward
                time = fp - cp

                for x in range(cp +1, fp + 1):
                    positions.append(x)

                i += time
            
            elif fp == cp:
                # stay here just move one step afterward
                positions.append(fp)
                i += 1

            else:
                # move backward
                time = cp - fp
                
                while(fp<cp):
                    positions.append(cp-1)
                    cp -= 1

                i += time
            
        else:
            
            positions.append(positions[i])

            i += 1
    print(positions)

    tests -=1
