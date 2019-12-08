/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int hasPathSum1(TreeNode* A,int B)
{
    if(A==NULL)
        return 0;
    B-=A->val;
    if(A->left==NULL&A->right==NULL)
    {
        if(B==0)return 1;
        return 0;
    }
    int x= hasPathSum1(A->left,B);
    int y= hasPathSum1(A->right,B);
    if(x==1||y==1)
        return 1;
    return 0;
}
int Solution::hasPathSum(TreeNode* A, int B) {
        return hasPathSum1(A,B);
}
