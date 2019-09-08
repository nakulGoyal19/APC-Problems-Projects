#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivotIndex = low+rand()%(high-low+1);
    int pivot = arr[pivotIndex];
    int i = (low - 1);
    int j;
    swap(&arr[pivotIndex], &arr[high]);
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int n,i;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    printf("Array after sorting: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
