# A min heap has all elements below it greater than the parent
# Every node in a heap is itself a heap

from heapq import heapify, heappop
# It creates a min heap
# Multiply by -1 to use it as a max heap

def heap_sort(inp):
    lst = inp.copy()
    
    heapify(lst)

    arr = []
    for i in range(len(lst)):
        arr.append(heappop(lst))


    return arr

if __name__ == '__main__':
    lst = [3, 5, 6, 2, 4, 1, 9, 8, 10]
    print(heap_sort(lst))
