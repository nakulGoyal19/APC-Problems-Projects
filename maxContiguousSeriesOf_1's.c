#include<stdio.h>
//solution by sliding window algorithm.
int main(){
    int n,i=0,l=0,r=0,c,N,max=-1,si=0,ei=0;
    printf("Enter size of binary array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements in array (0 or 1 only): ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter no. of changable 0's: ");
    scanf("%d",&N);
    c=N;
    max=-1;
    while(r<n)
    {
        if(a[r]==1)
        {
            r++;
        }
        else if(a[r]==0&&c>0)
        {
            r++;c--;
        }
        else if(a[r]==0)
        {
            while(a[l]!=0)
            {
                l++;
            }
            l++;
            if(c<N)
                c++;
        }
        if(l>r)
        {
            r=l;
        }
        printf("%d %d %d %d ",l,r,si,ei);
        if(max<(r-l))
        {
            si=l;ei=r-1;
            max=r-l;
        }
    }
    printf("\nMax continuous series of 1 is: %d from index %d to %d",max,si,ei);
}
