#%% Find median of two sorted arrays
# Uses Binary search to split the array into halfs
# Using the youtube video approach, see
# We have to find the partioning position of both the arrays
# A and B

import math

def small_large(ar1, ar2):
    if len(ar1) <= len(ar2):
        return ar1.copy(), ar2.copy()
    else:
        return ar2.copy(), ar1.copy()

def solve(ar1, ar2):
    # assumption ar1 is smaller than ar2
    smar, lgar = small_large(ar1, ar2)
    
    x = len(smar)
    y = len(lgar)

    # we are going to split the x array
    low = 0
    high = x

    while(low <= high):
        partition_x = (low + high) // 2
        partition_y = (x + y + 1) // 2 - partition_x

        left_x = float('-inf') if partition_x == 0 else smar[partition_x - 1]
        right_x = float('inf') if partition_x == x else smar[partition_x]

        left_y = float('-inf') if partition_y == 0 else lgar[partition_y - 1]
        right_y = float('inf') if partition_y == y else lgar[partition_y]
    
        # Now check if this is the right partition
        if (left_x <= right_y and left_y <= right_x):
            print(left_x, left_y, right_x, right_y)
            if (x + y) % 2 == 0:
                return (max(left_x, left_y) + min(right_x, right_y)) / 2
            else:
                return max(left_x, left_y)
        elif left_x > right_y:
            high = partition_x - 1
        else:
            low = partition_x + 1

ar1 = [1, 3]
ar2 = [2]

print(solve(ar1, ar2))