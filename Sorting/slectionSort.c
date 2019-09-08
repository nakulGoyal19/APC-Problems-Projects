#include<stdio.h>
void selectionSort(int *a,int n)
{
    int min,j,i,index,temp;
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                index=j;
            }
        }
        if(index!=j)
        {
            temp=a[i];
            a[i]=a[index];
            a[index]=temp;
        }
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
    selectionSort(a,n);
    printf("Array after sorting: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
