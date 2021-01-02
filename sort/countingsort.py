# Here we will try counting sort
# Considered all element to be greater than or equal to zero!

def counting_sort(lst):

    # 1. First find the max element i.e. K
    K = lst[0]

    for x in lst:
        K = max(K, x)

    countArray = [0 for i in range(K + 1)]

    # Now add the counters
    for x in lst:
        countArray[x] += 1


    # Now make the prefix sum array of it
    for i in range(1, K+1):
        countArray[i] = countArray[i] + countArray[i-1]

    # Now we will again loop in lst and making decrementing the counter
    ans = [0 for i in range(len(lst))]

    for x in lst:
        ans[countArray[x] - 1] = x
        countArray[x] -= 1

    return ans


def counting_sort_by_me(lst):
    '''  Not sure of time complexity of this though '''
    # 1. First find the max element i.e. K
    K = lst[0]

    for x in lst:
        K = max(K, x)

    countArray = [0 for i in range(K + 1)]

     # Now add the counters
    for x in lst:
        countArray[x] += 1

    ans = []
    # print(countArray)
    for i in range(K+1):
        for j in range(countArray[i]):
            ans.append(i)

    return ans
    

if __name__ == '__main__':
    lst = [3, 5, 6, 2, 3, 1, 9, 8, 10]
    print(counting_sort(lst))

    lst = [3, 5, 6, 2, 3, 1, 9, 8, 10]
    print(counting_sort_by_me(lst))
