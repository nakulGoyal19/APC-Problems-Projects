/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int searchIndex(vector<int> &A,int inS,int inE,int val)
{   
    for(int i=inS;i<=inE;i++)
    {
        if(A[i]==val)
            return i;
    }
}

TreeNode* buildTree1(vector<int> &A, vector<int> &B,int inS,int inE,int &postIndex)
{
    if(inS>inE)
        return NULL;
    TreeNode* newRoot = new TreeNode(B[postIndex--]);
    if(inS==inE)
        return newRoot;
    
    int inIndex = searchIndex(A,inS,inE,newRoot->val);
    
    newRoot->right=buildTree1(A,B,inIndex+1,inE,postIndex);
    newRoot->left=buildTree1(A,B,inS,inIndex-1,postIndex);
    return newRoot;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int postIndex=B.size()-1;
    return buildTree1(A,B,0,B.size()-1,postIndex);
}
