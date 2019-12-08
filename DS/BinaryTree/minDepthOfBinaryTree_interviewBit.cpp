/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    int val= 1+min(minDepth(A->left),minDepth(A->right));
    if(val>1)
        return val;
    if(minDepth(A->left)==0)
        return 1+minDepth(A->right);
    else
        return 1+minDepth(A->left);
}
