'''

Till 10**6 only

'''
r = 10**6 + 5

arr = [True for i in range(r)]

for i in range(2, r):

    # Now start the loop from here and keep adding all
    for j in range(i+i, r, i):
        arr[j] = False

print(arr[:30])
