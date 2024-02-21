#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
void printVet(int* vet, int n);

/*Implementação do Merge Sort*/

void mergeOriginal(int* vet, int inicio, int meio, int fim);
void mergeSortOriginal(int *vet, int inicio, int fim);

/*Comentários do Chat-GPT

 Merge Sort is an efficient, divide-and-conquer sorting algorithm with a time complexity of O(n log n) in the worst case.
 However, there are some improvements you can make to enhance its performance and make the code more robust:

1 - Optimize Memory Allocation: Instead of allocating memory for the temporary array within the merge function,
you can allocate it once in the mergeSort function. This will reduce the overhead of frequent memory allocations
and deallocations. Also, make sure to free the allocated memory after sorting.

2 - Avoid Recursion for Small Subarrays: For very small subarrays, recursion can add overhead.
You can set a threshold below which the algorithm uses a simpler sorting algorithm like insertion sort. This can be faster for small arrays.

3 - Use Iterative Merge: Merge can be implemented iteratively, which can save function call overhead and possibly improve performance.


This code improves memory allocation and adds a threshold for switching to insertion sort for small subarrays.
You can adjust the threshold as needed to find the optimal balance between recursion overhead and sorting efficiency.
*/

void mergeGPT(int* vet, int inicio, int meio, int fim);
void mergeSortGPT(int* vet, int inicio, int fim);

/*Implementação do Insertion Sort*/

/* Comentários do Chat-GPT

While Insertion Sort is not the fastest sorting algorithm for large datasets, you can optimize it further:

Binary Search for Insertion Point: Instead of shifting elements one by one to find the insertion point,
you can use a binary search to locate the correct position for the current element.
This will reduce the number of comparisons in the inner loop.

Use a Temp Variable: In the inner loop, use a temporary variable to store the current element you are
trying to insert, and only make a single assignment to the array after finding the correct position.
This reduces the number of assignments.

By using binary search to find the correct insertion point, this code reduces the number of comparisons
and assignments in the inner loop. It will make the Insertion Sort algorithm slightly faster, especially for larger datasets.
*/

void insertionSortOriginal(int *vet, int n);
void insertionSortGPT(int *vet, int n);

#endif // FUNCTIONS_H_INCLUDED
