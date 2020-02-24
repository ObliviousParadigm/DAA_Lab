#include <stdio.h>
#include "mergeSort.h"
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int firsthalf_len = -start + mid + 1, secondhalf_len = end - mid;
    int firsthalf[firsthalf_len], secondhalf[secondhalf_len];
    int index = 0, i, j, k = start;
    for (i = 0; i < firsthalf_len; i++)
    {
        index = start + i;
        firsthalf[i] = a[index];
    }
    for (j = 0; j < secondhalf_len; j++)
    {
        index = mid + 1 + j;
        secondhalf[j] = a[index];
    }
    i = 0;
    j = 0;
    while (i < firsthalf_len && j < secondhalf_len)
    {
        if (firsthalf[i] < secondhalf[j])
        {
            a[k] = firsthalf[i];
            i++;
        }
        else
        {
            a[k] = secondhalf[j];
            j++;
        }
        k++;
    }
    while (i < firsthalf_len)
    {
        a[k] = firsthalf[i];
        k++;
        i++;
    }
    while (j < secondhalf_len)
    {
        a[k] = secondhalf[j];
        k++;
        j++;
    }
}
/*you need to design a scheduler that will schedule a set of tasks,
a number of the tasks need to wait for some other tasks to complete prior to running themselves. What algorithm 
could be used to design the scheduler and how would you implement it*/
// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end - 1) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        mergeSortedHalfs(a, start, mid, end);
    }
}

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *arr, int start, int end)
{
    int n = end - start + 1;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to
void selectiveMergeSort(int *a, int start, int end, int parameter)
{
    if (start - end + 1 > parameter)
        mergeSort(a, start, end);
    else
        insertionSort(a, start, end);
}
