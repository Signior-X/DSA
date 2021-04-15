'''

Till 10**6 only

'''
r = 10**6 + 5

minPrime = [i for i in range(r)]

for i in range(2, r):

    # Now start the loop from here and keep adding all
    for j in range(i+i, r, i):
        if minPrime[j] == j:
            minPrime[j] = i

print(minPrime[:30])

# Using this one can find if a number is prime or what is it's smaller prime divisor
# Also if it is itself => Prime number though ignoring 0 and 1
