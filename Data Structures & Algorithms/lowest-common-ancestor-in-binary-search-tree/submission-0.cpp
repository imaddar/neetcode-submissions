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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we have a pointer to nodes p and q.
        // we can store the list of ancestors from root to node p and node q
        // we can compare this list of ancestors
        // the last node until their paths diverge is the LCA
        TreeNode* ptr = root;
        queue<TreeNode*> p_queue;
        queue<TreeNode*> q_queue;
        TreeNode* lca;

        while (ptr != p) {
            p_queue.push(ptr);
            if (p->val > ptr->val) {
                ptr = ptr->right;
            } else if (p->val < ptr->val) {
                ptr = ptr->left;
            }
        }
        p_queue.push(ptr);
        
        ptr = root;
        while (ptr != q) {
            q_queue.push(ptr);
            if (q->val > ptr->val) {
                ptr = ptr->right;
            } else if (q->val < ptr->val) {
                ptr = ptr->left;
            }
        }
        q_queue.push(ptr);

        // while (!q_queue.empty()) {
        //         cout << q_queue.front()->val << " ";
        //         q_queue.pop();
        //     }
        //     cout << endl;

        // while (!p_queue.empty()) {
        //         cout << q_queue.front()->val << " ";
        //         q_queue.pop();
        //     }
        //     cout << endl;

        while (!p_queue.empty() and !q_queue.empty()) {
            if (p_queue.front() == q_queue.front()) {
                lca = p_queue.front();
                p_queue.pop();
                q_queue.pop();
            }
            else {
                return lca;
            }
        }

        return lca;
    }
};
