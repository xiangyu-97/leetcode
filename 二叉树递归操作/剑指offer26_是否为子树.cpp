/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* A, TreeNode* B) {
        if( !A &&  B )          return false;
        if(  A && !B )          return true;
        if( !A && !B )          return true;
        if( A->val != B->val )  return false;
        return isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if( !A || !B ) return false;
        if( A->val == B->val && isSameTree(A,B) ){ return true; }
        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};
