#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *, int, int); 
void merge(int *, int, int, int) ;


int main()
{
    int n, i, j, *arr;
    printf("\nEnter the number of elements:\t");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    
    for (i = 0; i < n; i++){
        printf("\nelement %d:\t", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nYou Entered:\n\n");
    for (j = 0; j < n; j++){
        printf("%d\t", arr[j]);
    }

    mergeSort(arr, 0, n-1);
    
    printf("\nSorted array is:-\n");
    
    for (int k = 0; k < n; k++){
        printf("%d\t", arr[k]);
    }

    free(arr);
    return 0;
}


void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void merge(int *arr, int l, int m, int r)
{
    int i, j, k, *arr1, *arr2;
    int n1 = (m - l + 1);
    int n2 = (r - m);

    arr1 = (int *)malloc(n1 * sizeof(int));
    arr2 = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        arr1[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        arr2[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    free(arr1);
    free(arr2);
}
