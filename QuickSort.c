//Program for QUICK SORT Algorithm...
/*
            pivot
             _^_________________________
            |   |   |   |   |   |   |   |
        arr | 5 | 9 |10 | 3 | 2 | 8 | 1 |
            |___|___|___|___|___|___|___|
              0   1   2   3   4   5   6
              ^                       ^
             left                   right

*/

#include <stdio.h>
#include <stdlib.h>

//Function call...
void quickSort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int *);

//Main function...
int main()
{
    int n, i, *arr;
    printf("Enter the no of elements to sort:\t");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element:\t");
        scanf("%d", &arr[i]);
    }
    printf("\nYou entered:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d\t", arr[j]);
    }

    //Quick Sort function call...
    quickSort(arr, 0, n-1);

    printf("\nSorted array is:\n");
    for (int k = 0; k < n; k++)
    {
        printf("%d\t", arr[k]);
    }

    free(arr);
    return 0;
}

void quickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int m = partition(arr, left, right);
        quickSort(arr, left, m-1);
        quickSort(arr, m+1, right);
    }
}
int partition(int *arr, int left, int right)
{
    int i = left, j = right, pivot = arr[left];
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[left], &arr[j]);

    return j;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}