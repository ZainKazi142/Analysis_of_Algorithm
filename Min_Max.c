#include <stdio.h>
// Structure to store both maximum and minimum elements
struct Pair
{
    int max;
    int min;
};
// Function to find maximum and minimum using Divide and Conquer
struct Pair maxMinDivideConquer(int arr[], int low, int high)
{
    struct Pair result;
    struct Pair left;
    struct Pair right;
    int mid;
    // Case 1: Only one element
    if (low == high)
    {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    // Case 2: Two elements
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Case 3: More than two elements → Divide into two halves
    mid = (low + high) / 2;
    left = maxMinDivideConquer(arr, low, mid);
    right = maxMinDivideConquer(arr, mid + 1, high);
    // Merge results from left and right halves
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;
    return result;
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    struct Pair result = maxMinDivideConquer(arr, 0, n - 1);
    printf("Maximum element is: %d\n", result.max);
    printf("Minimum element is: %d\n", result.min);
    return 0;
}