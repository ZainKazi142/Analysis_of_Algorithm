#include<stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low+high)/2;

        if (arr[mid] == key)
        {
            return mid;
        }

        else if(arr[mid] < key)
        {
            low = mid +1;
        }

        else(arr[mid] > key);
        {
            high = mid - 1;
        }
    return -1;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of Array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter key value:\n");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
    {
        printf("The key value (%d) is found at: %d <= (0-based index)", key, result);
    }
    else
    {
        printf("Key not found in given array.");
    }

    return 0;
}