
#include <stdio.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void main() {
    int arr[70],n;
    int arr_size;
    printf("Enter the number of array elements: ");
    scanf("%d",&arr_size);
    for(int i=0;i<arr_size;i++)
    {
        printf("\nElement %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Given array:\n");
    for(int i=0;i<arr_size;i++)
    {
        printf("%d\t",arr[i]);
    }
    quickSort(arr, 0, arr_size - 1);
    printf("\nSorted array:\n");
    for(int i=0;i<arr_size;i++)
    {
        printf("%d\t",arr[i]);
}
}
