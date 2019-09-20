#include<stdio.h>
//tree
typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
}treeNode;

//binary search tree for input
treeNode* BST(treeNode* root,int data)
{
    if(root==NULL)
    {
        treeNode* n=(treeNode*)malloc(sizeof(treeNode));
        n->data=data;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    else if(data<root->data)
    {

        root->left=BST(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=BST(root->right,data);
    }
    return root;
}

//create the tree as an input
void createTree(treeNode** root)
{
    int n,i;
    printf("Enter size of tree:");
    scanf("%d",&n);
    printf("\nEnter elements in order in BST : ");
    for(i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        *root=BST(*root,k);
    }
}

//stack
typedef struct stack
{
    treeNode* node;
    struct stack* next;
}stack;
void push(stack** st,treeNode* n)
{
    stack* new=(stack*)malloc(sizeof(stack));
    new->node=n;
    if(*st==NULL)
    {
        *st=new;
        new->next=NULL;
    }
    else
    {
        new->next=*st;
        *st=new;
    }
}
void pop(stack** st)
{
    *st=(*st)->next;
}
treeNode* top(stack* st)
{
    return st->node;
}

//inOrderTraversal
void inOrderTraversal(treeNode* root)
{
    printf("InOrder: ");
    stack* st=(stack*)malloc(sizeof(stack));
    st=NULL;
    treeNode* curr=root;
    while(curr||st)
    {
        while(curr)
        {
            push(&st,curr);
            curr=curr->left;
        }
        printf("%d ",top(st)->data);
        curr=top(st)->right;
        pop(&st);

    }


}

int main()
{
    treeNode* root=NULL;
    createTree(&root);
    inOrderTraversal(root);
}
