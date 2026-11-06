#include <stdio.h>

int findMax(int arr[], int size)
{
    int max = arr[0];
    int i;
    for (i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {10, 45, 23, 89, 12};
    int size = 5;
    printf("Largest element is %d\n", findMax(arr, size));
    return 0;
}
