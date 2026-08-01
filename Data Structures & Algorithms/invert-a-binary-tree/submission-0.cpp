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
    TreeNode* invertTree(TreeNode* root) {
        // to invert, we just need to switch the left and right pointer
        if (root == nullptr) {
            return nullptr;
        }
        // pointer semantics
        // 
        TreeNode* temp = root->left;

        root->left = root->right;
        root->right = temp;
    
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
