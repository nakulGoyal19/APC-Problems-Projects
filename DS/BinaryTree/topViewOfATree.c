#include<stdio.h>
//Tree
typedef struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
}Tree;

//STree
typedef struct STree
{
    struct Tree* Tnode;
    int dist;
}STree;

//queue implementation
typedef struct queue
{
    struct STree* st;
    struct queue* next;
}queue;
void push(queue** front,queue** rear,STree* s)
{
    queue* n=(queue*)malloc(sizeof(queue));
    n->st=s;
    n->next=NULL;
    if(*front==NULL&&*rear==NULL)
    {
        *front=n;
        *rear=n;
    }
    else
    {
        (*rear)->next=n;
        *rear=n;
    }
}
void pop(queue** front,queue** rear)
{
    if(*front==*rear)
    {
        *front=NULL;
        *rear=NULL;
    }
    else
    {
        *front=(*front)->next;
    }
}

//top view of tree implementation
void topView(Tree* root)
{
    int tV[101];
    int i=0;
    for(i=0;i<101;i++)
        tV[i]=0;
    int center=50;
    //put root node in queue
    STree* sroot=(STree*)malloc(sizeof(STree));
    sroot->Tnode=root;
    sroot->dist=0;
    queue* front=NULL;
    queue* rear=NULL;
    push(&front,&rear,sroot);
    //level order traversal using queue
    while(front&&rear)
    {
        //top view elements in array
        int index=front->st->dist;
        int value=front->st->Tnode->data;
        if(tV[center+index]==0)
            tV[center+index]=value;
        //check left
        if(front->st->Tnode->left)
        {
            STree* nn=(STree*)malloc(sizeof(STree));
            nn->dist=front->st->dist-1;
            nn->Tnode=front->st->Tnode->left;
            push(&front,&rear,nn);
        }
        //check right
        if(front->st->Tnode->right)
        {
            STree* nn=(STree*)malloc(sizeof(STree));
            nn->dist=front->st->dist+1;
            nn->Tnode=front->st->Tnode->right;
            push(&front,&rear,nn);
        }
        //remove that element from queue
        pop(&front,&rear);

    }
    //print top view
    printf("TOP VIEW: ");
    for(i=0;i<101;i++)
    {
        if(tV[i]!=0)
            printf("%d ",tV[i]);
    }
}

//Binary Search Tree for creation of tree(input)
Tree* BST(Tree* root,int data)
{
    if(root==NULL)
    {
        Tree* n=(Tree*)malloc(sizeof(Tree));
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
void createTree(Tree** root)
{
    *root=BST(*root,10);
    *root=BST(*root,6);
    *root=BST(*root,12);
    *root=BST(*root,7);
    *root=BST(*root,4);
    *root=BST(*root,11);
    *root=BST(*root,14);
    *root=BST(*root,5);
    *root=BST(*root,13);
    *root=BST(*root,3);
    *root=BST(*root,16);
    *root=BST(*root,15);
    *root=BST(*root,1);
    *root=BST(*root,2);
    printf("Elements pushed in Binary Search tree: 10 6 12 7 4 11 14 5 13 3 16 15 1 2\n");
}

//check the input.
void preorderPrintTree(Tree* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorderPrintTree(root->left);
    preorderPrintTree(root->right);
}
int main()
{
    Tree* root=NULL;
    createTree(&root);
    //printf("preorder Tree: ");
    //preorderPrintTree(root);
    //printf("\n");
    topView(root);
}
