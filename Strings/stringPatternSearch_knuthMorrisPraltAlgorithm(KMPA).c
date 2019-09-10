#include<stdio.h>

int main()
{
    char s[20]="abcxabcyabcdabcyabcd";
    char pattern[8]="abcyabcd";
    int lps[8];
    lps[0]=0;
    int i=0,j;
    for(j=1;j<8;j=j)
    {
        if(pattern[i]==pattern[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i==0)
            {
                lps[j]=0;j++;
            }
            else
                i=lps[i-1];
        }
    }
    for(i=0;i<8;i++)
        printf("%d ",lps[i]);
    printf("\n");
    j=0;
    for(i=0;i<=20;i=i)
    {
        if(j>=8)
        {
            printf("pattern found at %d\n",i-8);
            j=0;
        }
        if(s[i]==pattern[j])
        {
            i++;j++;
        }
        else
        {
            if(j==0)
            {
                i++;
            }
            else
                j=lps[j-1];

        }

    }

}
