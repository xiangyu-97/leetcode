/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levelOrder;
        vector<int> ret;
        if (!root) {
            return ret;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            levelOrder.push_back(vector <int> ());
            for (int k = currentLevelSize; k > 0 ; k--) {
                auto node = q.front(); q.pop();
                levelOrder.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }            
            ret.push_back(levelOrder.back().back());       
        }        
        return ret;
    }
};
