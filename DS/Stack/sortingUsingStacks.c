//stub starts
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 1000
typedef struct
{
int top;
int item[MAX];
}stack;
void init(stack *s)
{
s->top=-1;
}
int empty(stack *s)
{
return(s->top==-1);
}
int full(stack *s)
{
return(s->top==MAX-1);
}
void push(stack *s,int a)
{
if (full(s))
{
printf("stack is full");
exit(0);
}
else
s->item[++s->top]=a;
}
int pop(stack *s)
{
if(empty(s))
return (-1);
else
return(s->item[s->top--]);
}

int peek(stack *s)
{
    return s->item[s->top];
}
stack sort;
void sortfun(stack source,stack losers);
//stub ends here

//code starts
void sortfun(stack source,stack losers)
{
    while(!empty(&source))
    {
        if(empty(&sort))
            push(&sort,pop(&source));
        else
        {
            if(peek(&sort)>=peek(&source))
            {
                push(&sort,pop(&source));
            }
            else
            {
                while(!empty(&sort)&&peek(&source)>peek(&sort))
                {
                    push(&losers, pop(&sort));
                }
                push(&sort,pop(&source));
                while(!empty(&losers))
                {
                    push(&sort,pop(&losers));
                }
            }
        }
    }
}
//code ends
 
//stub starts
int main()
{
 stack source, losers;
 int exp[MAX],temp;
    int i,n,a[20],f,c;
scanf("%d", &n);
init(&source);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
push(&source,a[i]);
}
			init(&sort);
			init(&losers);
sortfun(source,losers);
    
      while(!empty(&sort))

	{            if(!empty(&sort))

      printf("%d\n",pop(&sort));
	 }
    return(0);}
//stub ends