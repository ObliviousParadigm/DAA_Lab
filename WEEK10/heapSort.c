// Header file for the implementation of Heap sort

typedef struct
{
  int *a;
  int size;
} Heap;

/**
 * Given an array a[], build a max heap by calling maxHeapify on each parent 
 * starting from the last non-leaf node(at n/2 - 1 th index) down to the root node(at 0th index).
 * Return a heap structure pointing to the same array a[], with size n.
 */
Heap buildMaxHeap(int *const a, int n)
{
  int i;
  Heap h;
  h.a = a;
  h.size = n;
  for (i = n / 2 - 1; i >= 0; --i)
    maxHeapify(h, i);
  return h;
}

/**
 * MAX_HEAPIFY: Compare h.a[idx] with its two children(if they exist), 
 * and swap the smallest of the three with the element at idx, 
 * and recursively call maxHeapify on the child node that got swapped.
 */
void maxHeapify(Heap h, int idx)
{
  int largest = idx;
  int lChild = 2 * idx + 1;
  int rChild = 2 * idx + 2;
  int temp;

  if (lChild < h.size && h.a[lChild] > h.a[largest])
    largest = lChild;

  if (rChild < h.size && h.a[rChild] > h.a[largest])
    largest = rChild;

  if (largest != idx)
  {
    temp = h.a[idx];
    h.a[idx] = h.a[largest];
    h.a[largest] = temp;

    maxHeapify(h, largest);
  }
}

/**
 * HEAP_SORT: Sort array a[] by first building max heap, 
 * and then, iteratively swap the max element with last element
 * and call heapify on the root node. Remember to decrease heap.size after each iteration.
 */
void heapSort(int *const a, int n)
{
  Heap h = buildMaxHeap(a, n);
  int i;
  int temp;
  for (i = n - 1; i >= 0; --i)
  {
    temp = h.a[i];
    h.a[i] = h.a[0];
    h.a[0] = temp;
    --h.size;

    maxHeapify(h, 0);
  }
}

/**
 * A great article to understand heap sort:
 * https://medium.com/basecs/heapify-all-the-things-with-heap-sort-55ee1c93af82
 */
