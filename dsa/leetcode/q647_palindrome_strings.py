#%% Palindrome substrings all
# we will be using manaches algorithm to do this taks in
# linear time

def solve(s):

    c = 0
    # find the count of all substrings

    # start manaches algo to create P
    T = "#|"
    for x in s:
        T += x + "|"

    T += "$"
    P = [0 for i in range(len(T))]

    C = 0 # For the centre of the current largest mirror
    R = 0 # the right extreme of the current laregest mirror

    for i in range(1, len(T) - 1):
        mirr = 2*C - i

        # copy using the mirror
        if (i < R):
            P[i] = min(R-i, P[mirr])

        # now expand it
        while(T[i + (1 + P[i])] == T[i - (1 + P[i])]):
            P[i] += 1

        if (i + P[i] > R):
            C = i
            R = i + P[i]

    # Now the P is ready
    print(P)

    for x in P:
        c += (x+1) // 2

    return c

a = solve('aabbaa')
print(a)
