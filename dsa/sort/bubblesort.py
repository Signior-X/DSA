def bubble_sort(arr):
    '''
    Bubble sort keep swaping that is it
    '''

    i = 0
    while (i < len(arr)):

        j = 0
        while j < len(arr) - 1:

            # swap the values here
            if arr[j+1] <= arr[j]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
            
            j += 1

        i += 1

    return arr


if __name__ == '__main__':
    lst = [3, 5, 6, 2, 4, 1, 9, 8, 10]
    print(bubble_sort(lst))
