# First we will define the merge operation which is very useful
import random

def merge(ar1, ar2):
    '''
    Here are two **sorted** piece of arrays may not be of same length
    We have to merge them in such a way that it will return the sorted merged
    result of the above two arrays
    '''

    i = 0
    j = 0
    mergedArr = []
    while(i < len(ar1) and j < len(ar2)):
        if ar1[i] <= ar2[j]:
            mergedArr.append(ar1[i])
            i += 1
        else:
            mergedArr.append(ar2[j])
            j += 1
    
    if i == len(ar1):
        # ar1 got finished to add the elements left ones
        mergedArr.extend(ar2[j:])
    else:
        mergedArr.extend(ar1[i:])
    
    return mergedArr


def merge_sort_recursion(arr):
    '''
    It uses the merge sort algorithm using the recursive method
    Uses the above `merge` function
    It is a divide and conquer strategy
    '''

    if len(arr) < 2:
        return arr

    mid = len(arr) // 2
    left = merge_sort_recursion(arr[:mid])
    right = merge_sort_recursion(arr[mid:])

    return merge(left, right)


if __name__ == '__main__':
    lst1 = [3, 6, 7]
    lst2 = [4, 8, 9, 10]

    print(merge(lst1, lst2))

    lst = [3, 5, 6, 2, 4, 1, 9, 8, 10]
    print(merge_sort_recursion(lst))


    # Driver code 
    arr = [random.randint(1, 10**6) for i in range(10**6 - 1)] 
    arr.append(10**6)

    print("arr", arr[:30])
    # Function Call 
    print(merge_sort_recursion(arr)[:30])
    


