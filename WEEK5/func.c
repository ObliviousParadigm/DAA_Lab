#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "session5_sort.h"
#include <time.h>

long int InsertionSort(Record *A, int n)
{
  Record temp;
  int i, j;
  long int counter = 0;

  for (i = 1; i < n; i++)
  {
    temp = A[i];
    j = i - 1;
    while (j >= 0)
    {
      counter++;
      if (A[j].serialnumber > temp.serialnumber)
      {
        A[j + 1] = A[j];
        A[j--] = temp;
      }
      else
        break;
    }
  }

  return counter;
}

long int BubbleSort(Record *A, int n)
{
  long int counter = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int isSorted = 1;
    for (int j = 0; j < n - i - 1; j++)
    {
      counter++;
      if (A[j].serialnumber > A[j + 1].serialnumber)
      {
        isSorted = 0;

        Record temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
    if (isSorted)
      break;
  }
  return counter;
}

long int SelectionSort(Record *A, int n)
{
  long int counter = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int min_index = i;
    for (int j = i + 1; j < n; j++)
    {
      counter++;
      if (A[j].serialnumber < A[min_index].serialnumber)
      {
        min_index = i;
      }
    }
    Record temp = A[i];
    A[i] = A[min_index];
    A[min_index] = temp;
  }
  return counter;
}
int binarySearch(Record* a, Record item, int low, int high) 
{ 
    if (high <= low) 
        return (item.serialnumber > a[low].serialnumber )?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item.serialnumber == a[mid].serialnumber) 
        return mid+1; 
  
    if(item.serialnumber > a[mid].serialnumber) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  

long int B_insertionSort(Record* a, int n) 
{ 
    int i, loc, j, k;
    float counter=0;
    Record selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        // find location where selected sould be inserted
        loc = binarySearch(a, selected, 0, j); 
  
        // Move all elements after location to create space 
        while (j >= loc) 
        { 
          counter++;
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
    return counter;
}

double time_elapsed(struct timespec start, struct timespec end)
{
  double t;
  t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
  t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
  return t;
}
Record *initialize(char *filename)
{

  int size = 100;
  FILE *filePointer;
  char dataToBeRead[size];
  filePointer = fopen(filename, "r");

  fgets(dataToBeRead, size, filePointer);
  int loop = atoi(dataToBeRead), score = 0;
  long int serial_no = 0;
  Record *A = (Record *)malloc(sizeof(Record) * loop);

  for (int i = 0; i < loop; i++)
  {
    fscanf(filePointer, "%ld %d", &serial_no, &score);
    A[i].serialnumber = serial_no;
    A[i].score = score;
    // printf("%ld %d\n",A[i].serialnumber,A[i].score);
  }
  fclose(filePointer);
  return A;
}
void algorithm(char *filename)
{
  Record *A;
  int size = 100;
  FILE *filePointer;
  char dataToBeRead[size];
  filePointer = fopen(filename, "r");
  fgets(dataToBeRead, size, filePointer);
  int loop = atoi(dataToBeRead);
  fclose(filePointer);
  long int counter = 0;
  struct timespec start, end;

  A = initialize(filename);
  clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
  counter = InsertionSort(A, loop);
  clock_gettime(CLOCK_REALTIME, &end); //end timestamp
  printf("Insertion Sort: %ld ", counter);
  printf("%lf\n", time_elapsed(start, end));
  // printf("No of comparisons: %ld\n\n", counter);

  A = initialize(filename);
  clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
  counter = B_insertionSort(A, loop);
  clock_gettime(CLOCK_REALTIME, &end); //end timestamp
  printf("Binary insertion Sort: %ld ", counter);
  printf("%lf\n", time_elapsed(start, end));
  
  A = initialize(filename);
  clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
  counter = BubbleSort(A, loop);
  clock_gettime(CLOCK_REALTIME, &end); //end timestamp
  printf("Bubble Sort: %ld ", counter);
  printf("%lf\n", time_elapsed(start, end));
  // printf("No of comparisons: %ld\n\n", counter);

  A = initialize(filename);
  clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
  counter = SelectionSort(A, loop);
  clock_gettime(CLOCK_REALTIME, &end); //end timestamp
  printf("Selection Sort: %ld ", counter);
  printf("%lf\n", time_elapsed(start, end));
  // printf("No of comparisons: %ld\n\n", counter);
}
