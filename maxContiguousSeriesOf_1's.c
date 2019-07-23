#include<stdio.h>
int main(){
    int n,i=0,l=0,r=0,c,N,max=0,si=0,ei=0;
    printf("Enter size of binary array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements in array (0 or 1 only): ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter no. of changable 0's: ");
    scanf("%d",&N);
    c=N;
    max=1;
    while(r<n-1)
    {
        if(a[l]==0)
        {
            l++;r++;
        }
        else if(a[r+1]==1)
        {
            r++;
        }
        else
        {
            if(c>0)
            {
                r++;c--;
            }
            else
            {
                l++;
                if(l>r)
                {
                    r++;
                }
                if(a[l-1]==0)
                {
                    c++;
                }
            }

        }
       // printf("%d %d  ",l,r);
        if(max<(r-l+1))
        {
            si=l;ei=r;
            max=r-l+1;
        }
    }
    printf("\nMax continuous series of 1 is: %d from index %d to %d",max,si,ei);
}
