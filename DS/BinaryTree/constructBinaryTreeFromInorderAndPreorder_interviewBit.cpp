/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int search(vector<int> &A,int inS,int inE,int value)
{
    for(int i=inS;i<=inE;i++)
    {
        if(A[i]==value)
            return i;
    }
}
TreeNode* builtTree1(vector<int> &A,vector<int> &B,int inS,int inE,int &preIndex)
{
    //static int preIndex=0;
    
    if(inS>inE)
        return NULL;
    TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
    newNode->val=A[preIndex++];
    newNode->left=NULL;
    newNode->right=NULL;
    if(inS==inE)
        return newNode;
    int inIndex=search(B,inS,inE,newNode->val);
    
    newNode->left=builtTree1(A,B,inS,inIndex-1,preIndex);
    newNode->right=builtTree1(A,B,inIndex+1,inE,preIndex);
    return newNode;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int preIndex=0;
    return builtTree1(A,B,0,A.size()-1,preIndex);
}
