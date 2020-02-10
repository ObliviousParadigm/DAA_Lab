#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include <time.h>

long int InsertionSort(Record *A, int n)
{
    int i, j;
    long int cnt = 0;
    Record temp;

    for (i = 0; i < n - 1; ++i)
    {
        temp = A[i];
        j = i - 1;

        while (j >= 0)
        {
            cnt++;
            if (A[j].score > temp.score)
            {
                A[j + 1] = A[j];
                j--;
            }
        }
        A[j + 1] = temp;
    }
    return cnt;
}

long int BubbleSort(Record *A, int n)
{
    int i, j;
    long int cnt = 0;
    Record temp;

    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cnt++;
            if (A[j].score > A[j + 1].score)
            {

                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    return cnt;
}

long int SelectionSort(Record *A, int n)
{
    int i, j;
    long int cnt = 0;
    int min_score = 0;
    int min_index = 0;
    Record temp;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            cnt++;
            if (A[min_index].score > A[j].score)
            {
                min_index = j;
            }
        }
        temp = A[i];
        A[i] = A[min_index];
        A[min_index] = temp;
    }
    return cnt;
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