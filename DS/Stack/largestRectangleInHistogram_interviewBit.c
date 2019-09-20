/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
typedef struct stack{
    int data;
    struct stack* next;
}st;
void push(st** top,int data)
{
    st* new=(st*)malloc(sizeof(st));
    new->data=data;
    new->next=*top;
    *top=new;
}
int peek(st* top)
{
    return top->data;
}
int empty(st* top)
{
    if(top==NULL)
        return 1;
    return 0;
}
void pop(st** top)
{
    st* temp=*top;
    *top=(*top)->next;
    free(temp);
    temp=NULL;
}
int largestRectangleArea(int* A, int n1) {
    st *s=NULL;
    int max=0,i=0;
    for(i=0;i<n1;i++)
    {
        if(empty(s)||A[i]>=A[peek(s)])
        {
            push(&s,i);
        }
        else
        {
            while(!empty(s)&&A[peek(s)]>A[i])
            {
                int x=A[peek(s)];
                pop(&s);
                int dist=empty(s)?i:i-peek(s)-1;
                int area=dist*x;
                if(max<area)
                    max=area;
            }
            push(&s,i);
        }
    }
    while(!empty(s))
    {
        int x=A[peek(s)];
        pop(&s);
        int dist=empty(s)?i:i-peek(s)-1;
        int area=dist*x;
        if(max<area)
            max=area;
    }
    return max;
}
