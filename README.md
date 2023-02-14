# QuickSort Concurrently

I parallelized the Quick Sort implementation using "future - async."
I used functional programming in this project, which means that the function parameters did not change their state. To reduce the size of the sub-arrays, I employed recursion.
In sequential quick sort, the array of elements is sorted by selecting one element as the "pivot," and then the remaining elements are arranged in relation to it, with smaller elements being placed before the pivot and larger ones being placed after it. This procedure is repeated until in are in order and su arrays are too tiny. then a result array is created by combining these arrays.