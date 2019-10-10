/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
typedef struct map
{
    int val;
    int index;
}map;
int cmp(const void* a,const void* b)
{
    return ((map*)a)->val-((map*)b)->val;
}
int maximumGap(const int* A, int n1) {
    if(n1==1)
    return 0;
    int i;
    map m[n1];
    for(i=0;i<n1;i++)
    {
        m[i].val=A[i];
        m[i].index=i;
    }
    qsort(m,n1,sizeof(m[0]),cmp);
    int max=-1;
    int min=m[0].index;
    for(i=1;i<n1;i++)
    {
        if(m[i].index<min)
            min=m[i].index;
        if(m[i].index-min>max)
            max=m[i].index-min;
    }
    return max;
}
