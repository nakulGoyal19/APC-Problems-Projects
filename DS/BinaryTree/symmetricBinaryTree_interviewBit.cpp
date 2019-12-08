/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isSymmetricNew(TreeNode* A,TreeNode* B)
{
    if(!A&&!B)return 1;
    if(!A||!B)return 0;
    return isSymmetricNew(A->left,B->right)&isSymmetricNew(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL)return 1;
    return isSymmetricNew(A->left,A->right);
}
