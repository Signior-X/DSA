def insertion_sort(arr):
    '''
    Implement insertion sort, take and place the element in the sorted piece
    '''

    i = 1
    while (i < len(arr)):
        key = arr[i]

        # Now move all element in arr till i which are smaller rightwards

        j = i-1
        while j>=0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        
        arr[j + 1] = key
        
        i += 1

    return arr


if __name__ == '__main__':
    lst = [3, 5, 6, 2, 4, 1, 9, 8, 10]
    print(insertion_sort(lst))
