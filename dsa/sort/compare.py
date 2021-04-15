from bubblesort import bubble_sort
from insertionsort import insertion_sort
from selectionsort import selection_sort
from mergesort import merge_sort_recursion
from heapsort import heap_sort
import time
import random

lst = [random.randint(1, 10**6) for i in range(10000000)]

x = time.time()

sorted(lst)

print(time.time() - x)
x = time.time()

heap_sort(lst)

print(time.time() - x)
x = time.time()

merge_sort_recursion(lst)

print(time.time() - x)
x = time.time()

insertion_sort(lst)

print(time.time() - x)
x = time.time()

selection_sort(lst)

print(time.time() - x)
x = time.time()

bubble_sort(lst)

print(time.time() - x)
x = time.time()
