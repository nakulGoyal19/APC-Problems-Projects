#include<stdio.h>
void split(char *arr,char ch)
{
    int k;
    printf("%s \n",arr);
    /*
    char **res=(char**)malloc(sizeof(char*));
    for(k=0;k<5;k++)
        res[k]=(char*)malloc(4*sizeof(char));*/
    char *res[10];
    int start=0,end=0,i=0;
    while(1)
    {
        //split
        while(arr[end]!=ch&&arr[end]!='\0')
        {
            end++;
        }
        //copy
        res[i++]=arr+start;
        //move forward
        if(arr[end]=='\0')
            break;
        arr[end]='\0';
        start=end+1;
        end=start;
    }
    k=0;
    for(k=0;k<i;k++)
    {
        printf("%s\n",res[k]);
    }
}
int main()
{
    //char arr[16]={'a','b','c',' ','x','y','z',' ','u','v','w',' ','e','f','g'};
    char arr[16]="abc xyz uvw efg";
    split(arr,' ');
}
