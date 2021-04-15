#%% Find the longest palindrome substring
## Naive approach is just to find all substrings and check for palindrome
## Better approach will be to use DP for which first find all 2 digit palindrome, 3 digit palindrome and so on.
## The best approach is to have a trach of largest palindrome string length and keeping i as center, spread in
## in different directions to find if any larger even or odd length palindrome string can be found
## A more better will be manachers algorithm

# spread about center approach
st = 'geeks'
max_length = 1

start = 0 # to keep track of when the larget palindrome will be needed
l = len(st)

for i in range(1, l):
    # Make i as the center of the palindrome string
    c1 = i - 1
    c2 = i

    # first find the even length palindromes
    while(c1>=0 and c2<l and st[c1] == st[c2]):

        if (c2 - c1 + 1) > max_length:
            # A more bigger string is found
            start = c1; max_length = c2 - c1 + 1

        c1 -= 1
        c2 += 1
    
    c1 = i
    c2 = i

    # now find the odd palindromes considering c2 as the center
    while(c1>=0 and c2<l and st[c1] == st[c2]):

        if (c2 - c1 + 1) > max_length:
            # A more bigger string is found
            start = c1; max_length = c2 - c1 + 1
        
        c1 -= 1
        c2 += 1
    
# Now we will have the start position and the legth of the longest substring
print(st[start:start+max_length])


#%% Manachers's Algorithms o(n)
# Here we take into account a center C about which we are
# condiering the current Center and R the right extrems untils
# Also there is a L (left extreme, not used though)
# we use the mirror based technique to solve the problem
# and prevent computations that were already done

st = "ababacd"

# we create T and P
T = "&#"
for x in st:
    T += x + "#"

T += "@"

P = [0 for i in range(len(T))]

C = 0; R = 0
mxl = 1
mxi = 2

for i in range(1, len(T) - 1):
    mirr = 2*C - i

    # Have an initial upto it is confirmed palindrome
    if (i < R):
        P[i] = min(R-i, P[mirr])
    
    # Now exxpand it to more to find the new R
    while(T[i + (1+P[i])] == T[i - (1+P[i])]):
        P[i] += 1
    
    # Now increase the count
    if (i+P[i] > R):
        C = i
        R = i + P[i]
    
    # For calculating the final answer
    if P[i] > mxl:
        mxl = P[i]
        mxi = i

print(st, C, R)
print(mxi, mxl)
print(P)

# Now the P array is created (this is important)
# now using mxi as the center, find the array that needs to be

ans = T[mxi]
start = mxi - 2
end = mxi + 2

if mxl % 2 == 0:
    # even length substring
    ans = ""
    start = mxi - 1
    end = mxi + 1

while len(ans) < mxl:
    ans = T[start] + ans + T[end]
    start -= 2
    end += 2

print(ans)
