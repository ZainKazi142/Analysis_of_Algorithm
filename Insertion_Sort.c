#include<stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i =0; i<n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)
{
    for(int i =0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The Original Array is:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("The Sorted Array is:\n");
    printArray(arr, n);

    return 0;
}