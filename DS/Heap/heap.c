#include<stdio.h>
int a[20];
int size=0;
void swap(int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}
void swim(int i)
{
    if(i==0)
        return;
    int p=i/2;
    if(a[p]<a[i])
    {
        swap(p,i);
        swim(p);
    }
}
void sink(int i)
{
    if(i>=size)
        return;
    int max=i;
    int l=i*2;
    int r=i*2+1;
    if(l<size&&a[l]>a[max])
        max=l;
    if(r<size&&a[r]>a[max])
        max=r;
    if(i!=max)
    {
        swap(i,max);
        sink(max);
    }
}
void insert(int k)
{
    a[size++]=k;
    swim(size-1);
}
int del_max()
{
    int k=get_max();
    swap(0,size-1);
    size--;
    sink(0);
    return k;
}
int get_max()
{
    return a[0];
}
void print()
{
    printf("Heap: ");
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    insert(9);
    insert(3);
    insert(8);
    insert(1);
    insert(2);
    insert(7);
    insert(5);
    insert(-1);
    insert(0);
    int s=size;
    int i;
    for(i=0;i<s;i++)
    {
        print();
        printf("Max: %d \n",get_max());
        a[size-1]=del_max();
    }
    printf("Array after sorting by heap sort: ");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    printf("\n");
}
