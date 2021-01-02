def selection_sort(arr):
    '''
    Implement selection sort, find and swap the numbers
    '''

    i = 0
    while (i < len(arr)):
        
        j = i
        mni = i
        mn = arr[i]
        while (j < len(arr)):
            if (arr[j] < mn):
                mn = arr[j]
                mni = j
            j += 1
        
        # now swap mni and i
        temp = arr[i]
        arr[i] = mn
        arr[mni] = temp
        
        i += 1

    return arr


if __name__ == '__main__':
    
    lst = [3, 5, 6, 2, 4, 1, 9, 8, 10]
    print(selection_sort(lst))
