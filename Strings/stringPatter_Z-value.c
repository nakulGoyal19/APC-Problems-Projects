#include<stdio.h>

int main()
{
    char s[20]="abcxabcyabcdabcyabcd";
    char pattern[8]="abcyabcd";
    char str[29]="abcyabcd$abcxabcyabcdabcyabcd";
    //char str[29]="aabxaabxcaabxaabxayaaaaaaaaaa";
    int z[29];
       // z[0]=0;
    int i,left=0,right=0;
    for(i=1;i<29;i++)
    {
        if(i>=right)
        {
            left=i;
            right=i;
            while(str[right]==str[right-left])
                right++;
            z[i]=right-left;

        }
        else
        {
            if(i+z[i-left]<right)
            {
                z[i]=z[i-left];
            }
            else
            {
                left=i;
                while(str[right]==str[right-left])
                    right++;
            z[i]=right-left;
            }
        }
    }
    for(i=0;i<29;i++)
        printf("%d ",z[i]);
    printf("\n");
    for(i=0;i<29;i++)
        {
            if(z[i]==8)
            {
                printf("Pattern found at index %d\n",i-9);
            }
        }


}
