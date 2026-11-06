#include <stdio.h>

void printArray(int arr[], int index, int size)
{
    if (index == size)
    {
        return;
    }
    printf("%d ", arr[index]);
    printArray(arr, index + 1, size);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    printf("Array elements: ");
    printArray(arr, 0, size);
    printf("\n");
    return 0;
}
