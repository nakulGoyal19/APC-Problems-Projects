#include<stdio.h>
int main(){
int a[10]={0,1,1,0,1,1,0,0,1,1};
int n=10; int N=1; int max=0;
    int i=0,l=0,r=0,c=N;
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
            max=r-l+1;
        }
    }
    printf("%d",max);
}
